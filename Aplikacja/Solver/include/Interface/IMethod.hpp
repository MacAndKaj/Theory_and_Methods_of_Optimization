//
// Created by maciek on 08.03.19.
//

#ifndef SOLVER_IMETHOD_HPP
#define SOLVER_IMETHOD_HPP

#include "SSolution.hpp"
#include "Functions/SObjectiveFunction.hpp"

#define IMETHODS_FRIENDSHIP friend class MethodsFactory;

class IMethod
{
public:
    virtual void startComputing() = 0;
    virtual void setFunction(std::unique_ptr<SObjectiveFunction>&) = 0;
    virtual SSolution getSolution() const = 0;
};

#endif //SOLVER_IMETHOD_HPP
