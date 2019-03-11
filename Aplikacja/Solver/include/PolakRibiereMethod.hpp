//
// Created by maciek on 08.03.19.
//

#ifndef SOLVER_POLAKRIBIEREMETHOD_HPP
#define SOLVER_POLAKRIBIEREMETHOD_HPP

#include "SVector.hpp"
#include "IMethod.hpp"

class PolakRibiereMethod: public IMethod
{
    METHOD_FRIENDSHIP
public:
    SSolution getSolution() const override;

    PolakRibiereMethod() = delete;
    PolakRibiereMethod(const PolakRibiereMethod&) = delete;
private:
    PolakRibiereMethod(float error, float minimalStepBetweenTwoPoints, float minimalDifferenceBetweenStepsValues,
        unsigned int numberOfIterations, const std::vector<SVector>& solutionVecor);
    float getBeta()const;

//--Algorithm parameters
    float _error;
    float _minimalStepBetweenTwoPoints;
    float _minimalDifferenceBetweenStepsValues;
    unsigned int _numberOfIterations;

//--solution vector including [x_0,x_1,...,x_n -> x_d]
    std::vector<SVector> _solutionVecor;
};

#endif //SOLVER_POLAKRIBIEREMETHOD_HPP
