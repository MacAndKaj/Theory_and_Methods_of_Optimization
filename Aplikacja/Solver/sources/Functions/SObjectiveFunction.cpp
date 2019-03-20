//
// Created by maciek on 09.03.19.
//

#include <Functions/SObjectiveFunction.hpp>
#include <Functions/SFunction.hpp>
#include <Functions/SGradient.hpp>
#include <Functions/SHessian.hpp>

SObjectiveFunction::SObjectiveFunction(unsigned int dimension, const SFunction& function, const SGradient& gradient,
    const SHessian& hessian)
    : _dimension(dimension)
    , _function(function)
    , _gradient(gradient)
    , _hessian(hessian)
{

}
