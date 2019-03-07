//
// Created by maciek on 08.03.19.
//

#ifndef SOLVER_POLAKRIBIEREMETHOD_HPP
#define SOLVER_POLAKRIBIEREMETHOD_HPP

#include "SVector.hpp"
#include "IMethod.hpp"

class PolakRibiereMethod: public IMethod
{
public:
    SSolution getSolution() const override;

private:
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
