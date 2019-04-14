//
// Created by maciek on 19.03.19.
//

#include <memory>
#include <Functions/FunctionsFactory.hpp>
#include <Functions/GradientWrapper.hpp>
#include <Logger/LoggersFactory.hpp>

std::shared_ptr<FunctionsFactory> FunctionsFactory::_instance;
std::once_flag FunctionsFactory::_onceFlag;

const std::shared_ptr<IFunctionsFactory>
FunctionsFactory::getInstance(const std::shared_ptr<IApplicationStorage>& applicationStorage)
{
    std::call_once(FunctionsFactory::_onceFlag, [applicationStorage](){
        _instance.reset(new FunctionsFactory(applicationStorage));
    });

    return _instance;
}

FunctionsFactory::FunctionsFactory(const std::shared_ptr<IApplicationStorage>& applicationStorage)
    : _applicationStorage(applicationStorage)
    , _log(LoggersFactory::getLoggersFactory().getLogger("FunctionsFactory"))
{
}

std::shared_ptr<FunctionWrapper>
FunctionsFactory::getFunctionFromString(const std::string& function, unsigned int dimension)
{
    std::string checkedFunction;
    for (int i = 0; i < function.size(); ++i)
    {
        if (i != function.size() - 1 and function[i] == '*' and function[i + 1] == '*')
        {
            checkedFunction += '^';
            ++i;
        }
        else
        { checkedFunction += function[i]; }
    }
    return _parser.parseToFunction(dimension, checkedFunction);
}

std::shared_ptr<GradientWrapper>
FunctionsFactory::getGradientForFunction(const std::shared_ptr<FunctionWrapper>& ptr)
{
    return std::make_shared<GradientWrapper>(ptr,_applicationStorage);
}

