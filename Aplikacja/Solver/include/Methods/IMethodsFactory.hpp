//
// Created by maciek on 01.04.19.
//

#ifndef SOLVER_IMETHODSFACTORY_HPP
#define SOLVER_IMETHODSFACTORY_HPP

#include <memory>
#include <vector>

class SVector;
class IMethod;

class IMethodsFactory
{
public:
    using MethodPtr = std::shared_ptr<IMethod>;

    virtual MethodPtr getPolakRibiereMethod(float error, float minimalStep, float minimalStepValues, unsigned int iterations,
        std::vector<SVector>& startingPoint) const = 0;
};

#endif //SOLVER_IMETHODSFACTORY_HPP
