//
// Created by maciek on 09.03.19.
//

#ifndef SOLVER_FUNCTION_HPP
#define SOLVER_FUNCTION_HPP

#include <functional>
#include "SVector.hpp"

class ObjectiveFunction
{
public:
    ObjectiveFunction() = delete;
    ObjectiveFunction(unsigned int dimension, const std::function<float(SVector&)>& func);
    ObjectiveFunction(unsigned int&& dimension, const std::function<float(SVector&)>& func);
    float operator()(SVector&) const;
private:
    unsigned int _dimension;
    std::function<float(SVector&)> _func;
};

#endif //SOLVER_FUNCTION_HPP
