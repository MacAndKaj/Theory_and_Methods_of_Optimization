//
// Created by maciek on 08.03.19.
//

#ifndef SOLVER_METHODSFACTORY_HPP
#define SOLVER_METHODSFACTORY_HPP

#include <mutex>
#include <memory>
#include <vector>
#include <list>
#include "IMethodsFactory.hpp"

class IMethod;
class SVector;

class MethodsFactory: public IMethodsFactory
{
    using MethodPtr = std::shared_ptr<IMethod>;
public:
    MethodsFactory::MethodPtr getPolakRibiereMethod(float error, float minimalStep, float minimalStepValues, unsigned int iterations,
        std::vector<SVector>& startingPoint) const override;

    static const std::shared_ptr<IMethodsFactory> getInstance();
    MethodsFactory(const MethodsFactory&) = delete;
private:
    MethodsFactory();

    static std::shared_ptr<MethodsFactory> _instance;
    static std::once_flag _onceFlag;
};

#endif //SOLVER_METHODSFACTORY_HPP
