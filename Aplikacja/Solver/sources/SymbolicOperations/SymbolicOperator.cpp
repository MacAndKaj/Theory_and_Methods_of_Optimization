//
// Created by maciek on 23.03.19.
//

#include <sstream>
#include <Logger/LoggersFactory.hpp>
#include <Functions/FunctionsFactory.hpp>
#include <Functions/FunctionWrapper.hpp>
#include <SymbolicOperations/SymbolicOperator.hpp>
#include <SymbolicOperations/PythonFileHelper.hpp>
#include <ApplicationStorage.hpp>

std::shared_ptr<SymbolicOperator> SymbolicOperator::_instance;
std::once_flag SymbolicOperator::_onceFlag;

SymbolicOperator::SymbolicOperator(const std::shared_ptr<IApplicationStorage>& applicationStorage)
    : _log(LoggersFactory::getLoggersFactory().getLogger("SymbolicOperator"))
    , _pythonFileHelper("derivatives.txt")
    , _functionsFactory(applicationStorage->getFunctionsFactory())
{

}

GradientVector SymbolicOperator::getDerivatives(const std::shared_ptr<FunctionWrapper>& wrapper) const
{
    if (not wrapper)
    {
        std::stringstream strm;
        strm << __FUNCTION__ << "| Error! FunctionWrapper is empty!";
        _log << strm.str();
        return {};
    }
    std::stringstream strm;
    strm << __FUNCTION__ << "| Computing derivative for " << wrapper->getExpressionString();
    _log << strm.str();

    auto scriptname = _pythonFileHelper
        .createPythonScript(wrapper->getExpressionString(), wrapper->getDimension());
    return readFromFile(scriptname, wrapper);
}

GradientVector
SymbolicOperator::readFromFile(std::string& scriptname,
    const std::shared_ptr<FunctionWrapper>& wrapper) const
{
    if (scriptname.empty())
    {
        _log << "["+std::string(__FUNCTION__) + "]| Error! Creating python file failed!";
        return {};
    }

    auto command = "python3 " + scriptname;
    system(command.c_str());
    command = "rm " + scriptname + " derivatives.txt";
    std::ifstream file("derivatives.txt", std::ios::in);
    if (file.bad())
    {
        _log << "["+std::string(__FUNCTION__) + "]| Error! Reading from file derivatives went wrong!";
        system(command.c_str());
        return {};
    }
    GradientVector ret;
    std::string buffer;
    while (std::getline(file,buffer))
    {
        _log << "["+std::string(__FUNCTION__) + "] derivative " + buffer;
        ret.emplace_back(
            _functionsFactory->getFunctionFromString(buffer, wrapper->getDimension()));
    }
    file.close();
    system(command.c_str());
    _log << "["+std::string(__FUNCTION__) + "]| Completed successfully";
    return ret;
}

const std::shared_ptr<ISymbolicOperator>
SymbolicOperator::getInstance(const std::shared_ptr<IApplicationStorage>& applicationStorage)
{
    std::call_once(SymbolicOperator::_onceFlag, [applicationStorage](){
        _instance.reset(new SymbolicOperator(applicationStorage));
    });

    return _instance;
}

