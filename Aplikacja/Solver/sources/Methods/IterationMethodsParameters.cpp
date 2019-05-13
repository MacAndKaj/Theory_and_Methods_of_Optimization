//
// Created by maciek on 03.04.19.
//

#include <algorithm>
#include <Methods/IterationMethodsParameters.hpp>
#include <Definitions_and_Helpers/Definitions.hpp>

IterationMethodsParameters::IterationMethodsParameters(const double& error,
    const double& minimalStepSize, const double& minimalStepFunctionDifference,
    const double& armijoParameter, const unsigned int maxNumberOfIterations)
    : _error(error)
    , _minimalStepSize(minimalStepSize)
    , _minimalStepFunctionDifference(minimalStepFunctionDifference)
    , _maxNumberOfIterations(maxNumberOfIterations)
    , _armijoMethodParameter(armijoParameter)
{
}

IterationMethodsParameters::IterationMethodsParameters()
    : _error(defaultSolutionGradientError)
    , _minimalStepSize(defaultSolutionStepError)
    , _minimalStepFunctionDifference(defaultSolutionValueError)
    , _maxNumberOfIterations(defaultIterationsNumber)
    , _armijoMethodParameter(defaultArmijoMethodParameter)
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

const double IterationMethodsParameters::getArmijoMethodParameter() const
{
    return _armijoMethodParameter;
}
