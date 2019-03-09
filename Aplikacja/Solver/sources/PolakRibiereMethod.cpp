//
// Created by maciek on 08.03.19.
//

#include <PolakRibiereMethod.hpp>

#include "PolakRibiereMethod.hpp"

float PolakRibiereMethod::getBeta() const
{
    return 0;
}

SSolution PolakRibiereMethod::getSolution() const
{
    return SSolution();
}

PolakRibiereMethod::PolakRibiereMethod(float error, float minimalStepBetweenTwoPoints,
    float minimalDifferenceBetweenStepsValues, unsigned int numberOfIterations,
    const std::vector<SVector>& solutionVecor)
    : _error(error)
    , _minimalStepBetweenTwoPoints(minimalStepBetweenTwoPoints)
    , _minimalDifferenceBetweenStepsValues(minimalDifferenceBetweenStepsValues)
    , _numberOfIterations(numberOfIterations)
    , _solutionVecor(solutionVecor)
{
}
