//
// Created by maciek on 08.03.19.
//

#include <Methods/MethodsFactory.hpp>
#include <Methods/PolakRibiereMethod.hpp>

std::shared_ptr<MethodsFactory> MethodsFactory::_instance;
std::once_flag MethodsFactory::_onceFlag;

MethodsFactory::MethodsFactory() = default;

const std::shared_ptr<IMethodsFactory> MethodsFactory::getInstance()
{
    std::call_once(MethodsFactory::_onceFlag, [](){
        _instance.reset(new MethodsFactory());
    });

    return _instance;
}

MethodsFactory::MethodPtr
MethodsFactory::getPolakRibiereMethod(double error, double minimalStep, double minimalStepValues, double armijoParameter,
    unsigned int iterations, std::shared_ptr<SSolution> startingPoint) const
{
    return std::shared_ptr<PolakRibiereMethod>(
        new PolakRibiereMethod({error, minimalStep, minimalStepValues,armijoParameter , iterations}, startingPoint));
}


