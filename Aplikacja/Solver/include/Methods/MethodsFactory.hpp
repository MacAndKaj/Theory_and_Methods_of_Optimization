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
    MethodsFactory::MethodPtr getPolakRibiereMethod(double error, double minimalStep, double minimalStepValues, double armijoParameter, unsigned int iterations,
        std::shared_ptr<SSolution>) const override;

    static const std::shared_ptr<IMethodsFactory> getInstance();
    MethodsFactory(const MethodsFactory&) = delete;
private:
    MethodsFactory();

    static std::shared_ptr<MethodsFactory> _instance;
    static std::once_flag _onceFlag;
};

#endif //SOLVER_METHODSFACTORY_HPP
