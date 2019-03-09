//
// Created by maciek on 08.03.19.
//

#ifndef SOLVER_IMETHOD_HPP
#define SOLVER_IMETHOD_HPP

#include "SSolution.hpp"
#define METHOD_FRIENDSHIP friend class MethodsFactory;

class IMethod
{
public:
    virtual SSolution getSolution() const = 0;
};

#endif //SOLVER_IMETHOD_HPP
