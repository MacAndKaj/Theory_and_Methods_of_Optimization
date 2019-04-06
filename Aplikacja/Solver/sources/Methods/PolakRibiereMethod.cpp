//
// Created by maciek on 08.03.19.
//

#include <Logger/LoggersFactory.hpp>
#include <Methods/PolakRibiereMethod.hpp>
#include <Functions/GradientWrapper.hpp>

PolakRibiereMethod::PolakRibiereMethod(const IterationMethodsParameters& parameters,
    const std::vector<SVector>& solutionVecor)
    : _parameters(parameters)
    , _solutionVecor(solutionVecor)
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

    auto gradient0 = _gradient->getGradientInPoint(*(_solutionVecor.end()));
    if (not gradient0)
    {
        std::string strm{"Solution found in point " + _solutionVecor.end()->toString()};
        _log << strm;
        problemSolved();
        return;
    }
    SVector vector_d = -(*gradient0);
    auto
    firstPoint = (*_solutionVecor.end()); //+
    optimizationOngoing(firstPoint);
    problemSolved();
}

bool PolakRibiereMethod::optimizationOngoing(SVector& firstPoint)
{
    _solutionVecor.reserve(
        _parameters.getMaxNumberOfIterations() + 1); //first solution point is starting point

    auto alfa = 0; //TODO obliczanie alfa!!!
    auto beta = 0;
    while (not isStopConditionFulfilled())
    {
        auto function_value_in_point = _function->operator ()(*_solutionVecor.end());
        if (not function_value_in_point)
        {
            _log << "Problem when evaluating function" + _function->getExpressionString() +
                    " in point " + firstPoint.toString();
            return false;
        }

        if (_callback) _callback();
        ++_currentIteration;
    }
    return true;
}

void PolakRibiereMethod::problemSolved()
{

}

void PolakRibiereMethod::setFunction(const std::shared_ptr<FunctionWrapper>& function)
{
    _function = function;
}

bool PolakRibiereMethod::isStopConditionFulfilled() const
{
    return getCurrentIteration() == _parameters.getMaxNumberOfIterations() or
           getErrorInCurrentPoint() <= _parameters.getError() or
           getLastStepSize() <= _parameters.getMinimalStepSize() or
           getLastStepFunctionDifference() <= _parameters.getMinimalStepFunctionDifference();
}

float PolakRibiereMethod::getLastStepFunctionDifference() const
{
    return 0;
}

float PolakRibiereMethod::getErrorInCurrentPoint() const
{
    return 0;
}

float PolakRibiereMethod::getLastStepSize() const
{
    return 0;
}

unsigned int PolakRibiereMethod::getCurrentIteration() const
{
    return 0;
}

void PolakRibiereMethod::updateParameters()
{

}



//-----------------------------------------------------------------------------------