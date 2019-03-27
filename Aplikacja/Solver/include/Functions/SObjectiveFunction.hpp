//
// Created by maciek on 09.03.19.
//

#ifndef SOLVER_SOBJECTIVEFUNCTION_HPP
#define SOLVER_SOBJECTIVEFUNCTION_HPP

#include "SFunction.hpp"
#include "SGradient.hpp"
#include "SHessian.hpp"

class SObjectiveFunction
{
public:
    SObjectiveFunction() = delete;
    SObjectiveFunction(unsigned int dimension, const SFunction& function, const SGradient& gradient,
        const SHessian& hessian);

private:
    unsigned int _dimension;
    SFunction _function;
    SGradient _gradient;
    SHessian _hessian;
};

#endif //SOLVER_SOBJECTIVEFUNCTION_HPP
