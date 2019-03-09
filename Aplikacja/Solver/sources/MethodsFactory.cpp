//
// Created by maciek on 08.03.19.
//

#include <MethodsFactory.hpp>
#include <PolakRibiereMethod.hpp>

std::unique_ptr<MethodsFactory> MethodsFactory::_instance;
std::once_flag MethodsFactory::_onceFlag;

MethodsFactory::MethodsFactory() = default;

MethodsFactory& MethodsFactory::getMethodsFactory()
{
    std::call_once(MethodsFactory::_onceFlag, [](){
        _instance.reset();
    });

    return *_instance;
}

MethodsFactory::MethodPtr MethodsFactory::getPolakRibiereMethod(float error, float minimalStep, float minimalStepValues,
    unsigned int iterations, std::vector<SVector>& startingPoint) const
{
    return std::shared_ptr<PolakRibiereMethod>(new PolakRibiereMethod(error, minimalStep, minimalStepValues, iterations, startingPoint));
}


