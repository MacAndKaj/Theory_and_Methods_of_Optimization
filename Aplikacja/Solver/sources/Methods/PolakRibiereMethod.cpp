//
// Created by maciek on 08.03.19.
//

#include <Methods/PolakRibiereMethod.hpp>
#include <Logger/LoggersFactory.hpp>

PolakRibiereMethod::PolakRibiereMethod(float error, float minimalStepBetweenTwoPoints,
    float minimalDifferenceBetweenStepsValues, unsigned int numberOfIterations,
    const std::vector<SVector>& solutionVecor)
    : _error(error)
    , _minimalStepSize(minimalStepBetweenTwoPoints)
    , _minimalStepFunctionDifference(minimalDifferenceBetweenStepsValues)
    , _maxNumberOfIterations(numberOfIterations)
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
    while (not isStopConditionFulfilled())
    {



        _callback();
        ++_currentIteration;
    }
}

void PolakRibiereMethod::setFunction(const std::shared_ptr<FunctionWrapper>& function)
{
    _function = function;
}

bool PolakRibiereMethod::isStopConditionFulfilled() const
{
    return getCurrentIteration() == _maxNumberOfIterations or
           getErrorInCurrentPoint() <= _error or
           getLastStepSize() <= _minimalStepSize or
           getLastStepFunctionDifference() <= _minimalStepFunctionDifference;
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