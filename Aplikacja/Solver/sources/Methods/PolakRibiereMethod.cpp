//
// Created by maciek on 08.03.19.
//
#include <iomanip>
#include <utility>
#include <sstream>
#include <iostream>
#include <SMatrix.hpp>
#include <Logger/LoggersFactory.hpp>
#include <Methods/PolakRibiereMethod.hpp>
#include <Functions/GradientWrapper.hpp>
#include <Functions/HessianWrapper.hpp>
#include <FunctionInPointParameters.hpp>

PolakRibiereMethod::PolakRibiereMethod(const IterationMethodsParameters& parameters,
    std::shared_ptr<SSolution> startingPoint)
    : _parameters(parameters)
    , _solutionVector(std::move(startingPoint))
    , _log(LoggersFactory::getLoggersFactory().getLogger("PolakRibiereMethod"))
{

}

SSolution PolakRibiereMethod::getSolution() const
{
    return *_solutionVector;
}

void PolakRibiereMethod::setCallbackWhenIterationDone(
    const std::function<void(FunctionInPointParameters)>& callback)
{
    _callback = callback;
}

bool PolakRibiereMethod::startComputing()
{
    _log << "I[" + std::string(__FUNCTION__) + "]| from point " +
            _solutionVector->getLastPoint().toString();
    auto success = false;
    if (isReadyToCompute())
    {
        _log << "I[" + std::string(__FUNCTION__) + "| start optimization process";
        success = optimizationOngoing();
    }

    if (success)
    {
        _log << "ISolution found in point " + _solutionVector->getLastPoint().toString();
        problemSolved();
    }
    else
    {
        _log << "EError while seeking a solution in point " +
                _solutionVector->getLastPoint().toString() +
                " Returning...";
    }
    return success;
}

bool PolakRibiereMethod::optimizationOngoing()
{
    std::stringstream strm;
    strm << "Begin computing with: e_g = " << _parameters.getError()
        << " e_s = " << _parameters.getMinimalStepSize()
        << " e_v = " << _parameters.getMinimalStepFunctionDifference()
        << " armijo = " << _parameters.getArmijoMethodParameter()
        << "iterations = " << _parameters.getMaxNumberOfIterations();
    _log << 'I' + strm.str();

    _minimalizeInDirectionHelper.setMinStepSize(_parameters.getMinimalStepSize());
    _minimalizeInDirectionHelper.setTau(_parameters.getArmijoMethodParameter());
    auto current_point = _solutionVector->getLastPoint();
    auto current_gradient = *(_gradient->getGradientInPoint(current_point));
    auto current_direction = -current_gradient;
    _currentIteration = 0;
    double alfa, beta;
    do
    {
        alfa = _minimalizeInDirectionHelper.getAlfa(current_direction, current_point);
        current_point = current_point + alfa * current_direction;
        _solutionVector->addNewPoint(current_point,*_function->operator()(current_point));
        auto previous_gradient = current_gradient;
        current_gradient = *(_gradient->getGradientInPoint(current_point));

        beta = getBeta(current_gradient, previous_gradient);
        current_direction = -current_gradient + current_direction * beta;

        if (_callback)
        {
            _callback({current_point, *_function->operator ()(current_point)});
        }
        ++_currentIteration;
    } while (not isStopConditionFulfilled());
    auto subdeterminants = _hessian->getHessianInPoint(current_point)->getSubDeterminants();
    for (const auto& det : subdeterminants)
    {
       std::cout << det << std::endl;
        if (std::fabs(det - double(0)) < std::numeric_limits<double>::epsilon()) return false;
    }
    return true;
}

void PolakRibiereMethod::problemSolved()
{

}

void PolakRibiereMethod::setFunction(const std::shared_ptr<FunctionWrapper>& function)
{
    _log << "I[" + std::string(__FUNCTION__) + "]| [ " + function->getExpressionString() + " ]";
    _function = function;
    _minimalizeInDirectionHelper.setFunctionWrapper(_function);
}

void PolakRibiereMethod::setGradient(const std::shared_ptr<GradientWrapper>& ptr)
{
    _gradient = ptr;
    _minimalizeInDirectionHelper.setGradientWrapper(_gradient);
}

bool PolakRibiereMethod::isStopConditionFulfilled() const
{
    if (getCurrentIteration() == _parameters.getMaxNumberOfIterations())
    {
        _log << "W[" + std::string(__FUNCTION__) + "] Too much iterations";
        return true;
    }
    else if (getErrorInCurrentPoint() <= _parameters.getError())
    {

        std::stringstream strm;
        strm << getErrorInCurrentPoint() << "<=" <<
            _parameters.getError();

        _log << "W[" + std::string(__FUNCTION__) + "] gradient error " + strm.str();
        return true;
    }
    else if (getLastStepSize() <= _parameters.getMinimalStepSize())
    {
        std::stringstream strm;
        strm << getLastStepSize() << "<=" <<
            _parameters.getMinimalStepSize();

        _log << "W[" + std::string(__FUNCTION__) + "] _step size " + strm.str();
        return true;
    }
    else if (getLastStepFunctionDifference() <= _parameters.getMinimalStepFunctionDifference())
    {

        std::stringstream strm;
        strm << getLastStepFunctionDifference() << "<=" <<
            _parameters.getMinimalStepFunctionDifference();

        _log << "W[" + std::string(__FUNCTION__) + "] last function values differences " +
                strm.str();
        return true;
    }
    return false;
}

double PolakRibiereMethod::getLastStepFunctionDifference() const
{
    auto lastPoint = _solutionVector->getLastPoint();
    auto secondToLastPoint = _solutionVector->getSecondLastPoint();
    return std::fabs(
        (*_function->operator ()(lastPoint)) - (*_function->operator ()(secondToLastPoint)));
}

double PolakRibiereMethod::getErrorInCurrentPoint() const
{
    auto gradientValue = _gradient->getGradientInPoint(_solutionVector->getLastPoint());
    return gradientValue->getCartesianNorm();
}

double PolakRibiereMethod::getLastStepSize() const
{
    auto lastPoint = _solutionVector->getLastPoint();
    auto secondToLastPoint = _solutionVector->getSecondLastPoint();
    return (secondToLastPoint - lastPoint).getCartesianNorm();
}

unsigned int PolakRibiereMethod::getCurrentIteration() const
{
    return _currentIteration;
}

double PolakRibiereMethod::getBeta(const SVector& currentG, const SVector& previousG) const
{

    auto up = ((currentG - previousG).transpose()) * currentG;
    auto down = (SVector(previousG).transpose()) * previousG;

    if (not up or not down)
    {
        _log << "E[" + std::string(__FUNCTION__) + "]| Problem when evaluating beta!";
        return 0;
    }
    return (*up) / (*down);
}

bool PolakRibiereMethod::isReadyToCompute() const
{
    return _function and _gradient;
}

void PolakRibiereMethod::setHessian(const std::shared_ptr<HessianWrapper>& hessian)
{
    _hessian = hessian;
}



//-----------------------------------------------------------------------------------