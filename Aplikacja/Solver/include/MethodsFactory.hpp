//
// Created by maciek on 08.03.19.
//

#ifndef SOLVER_METHODSFACTORY_HPP
#define SOLVER_METHODSFACTORY_HPP

#include <mutex>
#include <memory>
#include <vector>

class IMethod;
class SVector;

class MethodsFactory
{
    using MethodPtr = std::shared_ptr<IMethod>;
public:
    static MethodsFactory& getMethodsFactory();

    MethodsFactory::MethodPtr getPolakRibiereMethod(float error, float minimalStep, float minimalStepValues, unsigned int iterations,
        std::vector<SVector>& startingPoint) const;

    MethodsFactory(const MethodsFactory&) = delete;
    MethodsFactory& operator =(const MethodsFactory&) = delete;
private:
    MethodsFactory();

    static std::unique_ptr<MethodsFactory> _instance;
    static std::once_flag _onceFlag;
};

#endif //SOLVER_METHODSFACTORY_HPP
