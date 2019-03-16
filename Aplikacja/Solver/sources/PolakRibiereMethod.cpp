//
// Created by maciek on 08.03.19.
//

#include <PolakRibiereMethod.hpp>

#include "PolakRibiereMethod.hpp"

PolakRibiereMethod::PolakRibiereMethod(float error, float minimalStepBetweenTwoPoints,
    float minimalDifferenceBetweenStepsValues, unsigned int numberOfIterations,
    const std::vector<SVector>& solutionVecor)
    : _error(error)
    , _minimalStepSize(minimalStepBetweenTwoPoints)
    , _minimalStepFunctionDifference(minimalDifferenceBetweenStepsValues)
    , _maxNumberOfIterations(numberOfIterations)
    , _solutionVecor(solutionVecor)
{
}


SSolution PolakRibiereMethod::getSolution() const
{
    return SSolution();
}

void PolakRibiereMethod::startComputing()
{
    while (isStopConditionFulfilled())
    {


        ++_currentIteration;
    }
}

void PolakRibiereMethod::setFunction(std::unique_ptr<ObjectiveFunction>& function)
{
    _function = std::move(function);
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

//------------------------------- utils ---------------------------------------------

float PolakRibiereMethod::getBeta() const
{
    return 0;
}

SVector PolakRibiereMethod::getGradientInCurrentPoint() const
{
    return SVector();
}



//-----------------------------------------------------------------------------------