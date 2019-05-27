//
// Created by maciek on 01.04.19.
//

#ifndef SOLVER_IMETHODSFACTORY_HPP
#define SOLVER_IMETHODSFACTORY_HPP

#include <memory>
#include <vector>
#include <SSolution.hpp>

class SVector;
class IMethod;

class IMethodsFactory
{
public:
    using MethodPtr = std::shared_ptr<IMethod>;

    virtual MethodPtr getPolakRibiereMethod(double error, double minimalStep, double minimalStepValues,
        double armijoParameter, unsigned int iterations, std::shared_ptr<SSolution>) const = 0;
};

#endif //SOLVER_IMETHODSFACTORY_HPP
