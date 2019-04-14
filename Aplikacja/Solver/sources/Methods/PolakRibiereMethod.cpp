//
// Created by maciek on 08.03.19.
//

#include <Logger/LoggersFactory.hpp>
#include <Methods/PolakRibiereMethod.hpp>
#include <Functions/GradientWrapper.hpp>
#include <iomanip>
#include <sstream>
#include <iostream>

PolakRibiereMethod::PolakRibiereMethod(const IterationMethodsParameters& parameters,
    const std::vector<SVector>& solutionVecor)
    : _parameters(parameters)
    , _solutionVector(solutionVecor)
    , _log(LoggersFactory::getLoggersFactory().getLogger("PolakRibiereMethod"))
{

}

SSolution PolakRibiereMethod::getSolution() const
{
    return SSolution();
}

void PolakRibiereMethod::setCallbackWhenIterationDone(const std::function<void()>& callback)
{
    _callback = callback;
}

void PolakRibiereMethod::startComputing()
{
    _log << "[" + std::string(__FUNCTION__) + "]| from point " +
            _solutionVector.rbegin()->toString();
    auto success = optimizationOngoing();
    if (success)
    {
        _log << "Solution found in point " + _solutionVector.rbegin()->toString();
        problemSolved();
    }
    else
    {
        _log << "Error while seeking a solution in point " + _solutionVector.rbegin()->toString() +
                " Returning...";
    }
}

bool PolakRibiereMethod::optimizationOngoing()
{
    _minimalizeInDirectionHelper.setMinStepSize(_parameters.getMinimalStepSize());
    _solutionVector.reserve(
        _parameters.getMaxNumberOfIterations()); //first solution point is starting point
    auto current_point = *_solutionVector.rbegin();
    auto current_gradient = *(_gradient->getGradientInPoint(current_point));
    auto current_direction = -current_gradient;

    double alfa, beta;
    do
    {
        alfa = _minimalizeInDirectionHelper.getAlfa(current_direction, current_point);
        current_point = current_point + alfa * current_direction;
        _solutionVector.emplace_back(current_point);
        auto previous_gradient = current_gradient;
        current_gradient = *(_gradient->getGradientInPoint(current_point));

        beta = getBeta(current_gradient, previous_gradient);
        current_direction = -current_gradient + current_direction * beta;

        if (_callback) _callback();
        ++_currentIteration;
        std::cout << current_point.toString() << " val:  " << *_function->operator()(current_point) << std::setprecision(20) << std::endl;

    } while (not isStopConditionFulfilled());
    return true;
}

void PolakRibiereMethod::problemSolved()
{

}

void PolakRibiereMethod::setFunction(const std::shared_ptr<FunctionWrapper>& function)
{
    _function = function;
    _minimalizeInDirectionHelper.setFunctionWrapper(_function);
}

bool PolakRibiereMethod::isStopConditionFulfilled() const
{
    if (getCurrentIteration() == _parameters.getMaxNumberOfIterations())
    {
        _log << "[" + std::string(__FUNCTION__) + "] Too much iterations";
        return true;
    }
    else if (getErrorInCurrentPoint() <= _parameters.getError())
    {

        std::stringstream strm;
        strm << getErrorInCurrentPoint()<< "<=" <<
            _parameters.getError() ;

        _log << "[" + std::string(__FUNCTION__) + "] gradient error " + strm.str();
        return true;
    }
    else if (getLastStepSize() <= _parameters.getMinimalStepSize())
    {
        std::stringstream strm;
        strm << getLastStepSize() << "<=" <<
            _parameters.getMinimalStepSize();

        _log << "[" + std::string(__FUNCTION__) + "] step size " +strm.str();
        return true;
    }
    else if (getLastStepFunctionDifference() <= _parameters.getMinimalStepFunctionDifference())
    {

        std::stringstream strm;
        strm << getLastStepFunctionDifference() << "<=" <<
            _parameters.getMinimalStepFunctionDifference();

        _log << "[" + std::string(__FUNCTION__) + "] last function values differences " + strm.str();
        return true;
    }
    return false;
}

double PolakRibiereMethod::getLastStepFunctionDifference() const
{
    auto lastPoint = *_solutionVector.rbegin();
    auto secondToLastPoint = *(++_solutionVector.rbegin());
    return std::fabs(
        (*_function->operator ()(lastPoint)) - (*_function->operator ()(secondToLastPoint)));
}

double PolakRibiereMethod::getErrorInCurrentPoint() const
{
    auto gradientValue = _gradient->getGradientInPoint(*_solutionVector.rbegin());
    return gradientValue->getCartesianNorm();
}

double PolakRibiereMethod::getLastStepSize() const
{
    auto lastPoint = *_solutionVector.rbegin();
    auto secondToLastPoint = *(++_solutionVector.rbegin());
    return (secondToLastPoint - lastPoint).getCartesianNorm();
}

unsigned int PolakRibiereMethod::getCurrentIteration() const
{
    return _currentIteration;
}

void PolakRibiereMethod::updateParameters()
{

}

double PolakRibiereMethod::getBeta(const SVector& currentG, const SVector& previousG) const
{

    auto up = ((currentG - previousG).transpose()) * currentG;
    auto down = (SVector(previousG).transpose()) * previousG;

    if (not up or not down)
    {
        _log << "[" + std::string(__FUNCTION__) + "]| Problem when evaluating beta!";
        return 0;
    }
    return (*up) / (*down);
}

void PolakRibiereMethod::setGradient(const std::shared_ptr<GradientWrapper>& ptr)
{
    _gradient = ptr;
    _minimalizeInDirectionHelper.setGradientWrapper(_gradient);
}



//-----------------------------------------------------------------------------------