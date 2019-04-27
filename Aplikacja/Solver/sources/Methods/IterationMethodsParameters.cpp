//
// Created by maciek on 03.04.19.
//

#include <Methods/IterationMethodsParameters.hpp>
#include <algorithm>
#include <Solver/include/Methods/IterationMethodsParameters.hpp>

#include "Methods/IterationMethodsParameters.hpp"

IterationMethodsParameters::IterationMethodsParameters(const double error,
    const double minimalStepSize, const double minimalStepFunctionDifference,
    const unsigned int maxNumberOfIterations)
    : _error(error)
    , _minimalStepSize(minimalStepSize)
    , _minimalStepFunctionDifference(minimalStepFunctionDifference)
    , _maxNumberOfIterations(maxNumberOfIterations)
{
}

IterationMethodsParameters::IterationMethodsParameters(const IterationMethodsParameters& other)
    : _error(other._error)
    , _minimalStepSize(other._minimalStepSize)
    , _minimalStepFunctionDifference(other._minimalStepFunctionDifference)
    , _maxNumberOfIterations(other._maxNumberOfIterations)
{
}

const double IterationMethodsParameters::getError() const
{
    return _error;
}

const double IterationMethodsParameters::getMinimalStepSize() const
{
    return _minimalStepSize;
}

const double IterationMethodsParameters::getMinimalStepFunctionDifference() const
{
    return _minimalStepFunctionDifference;
}

const unsigned int IterationMethodsParameters::getMaxNumberOfIterations() const
{
    return _maxNumberOfIterations;
}

