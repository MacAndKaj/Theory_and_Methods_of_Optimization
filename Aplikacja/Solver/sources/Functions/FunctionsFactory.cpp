//
// Created by maciek on 19.03.19.
//

#include <memory>
#include <Functions/FunctionsFactory.hpp>
#include <Logger/LoggersFactory.hpp>

std::shared_ptr<FunctionsFactory> FunctionsFactory::_instance;
std::once_flag FunctionsFactory::_onceFlag;

const std::shared_ptr<IFunctionsFactory> FunctionsFactory::getInstance()
{
    std::call_once(FunctionsFactory::_onceFlag, [](){
        _instance.reset();
    });

    return _instance;
}

FunctionsFactory::FunctionsFactory()
    : _log(LoggersFactory::getLoggersFactory().getLogger("FunctionsFactory"))
{
}

std::shared_ptr<FunctionWrapper>
FunctionsFactory::parseStringToSFunction(const std::string& function, unsigned int dimension)
{
    return _parser.parseToFunction(dimension, function);
}

