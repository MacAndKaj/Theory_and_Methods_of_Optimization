//
// Created by maciek on 03.04.19.
//

#include "Methods/IterationMethodsParameters.hpp"

IterationMethodsParameters::IterationMethodsParameters(const float error,
    const float minimalStepSize, const float minimalStepFunctionDifference,
    const unsigned int maxNumberOfIterations)
    : _error(error)
    , _minimalStepSize(minimalStepSize)
    , _minimalStepFunctionDifference(minimalStepFunctionDifference)
    , _maxNumberOfIterations(maxNumberOfIterations)
{

}

const float IterationMethodsParameters::getError() const
{
    return _error;
}

const float IterationMethodsParameters::getMinimalStepSize() const
{
    return _minimalStepSize;
}

const float IterationMethodsParameters::getMinimalStepFunctionDifference() const
{
    return _minimalStepFunctionDifference;
}

const unsigned int IterationMethodsParameters::getMaxNumberOfIterations() const
{
    return _maxNumberOfIterations;
}
