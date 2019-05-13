//
// Created by maciek on 19.03.19.
//

#ifndef SOLVER_FUNCTIONGETTER_HPP
#define SOLVER_FUNCTIONGETTER_HPP

#include <Functions/IFunctionsFactory.hpp>
#include <IApplicationStorage.hpp>
#include "ParserWrapper.hpp"

class ParserWrapper;

class FunctionsFactory : public IFunctionsFactory
{
public:
    static const std::shared_ptr<IFunctionsFactory> getInstance(
        const std::shared_ptr<IApplicationStorage>&);
    std::shared_ptr<FunctionWrapper> getFunctionFromString(const std::string&,
        unsigned int) override;
    std::shared_ptr<GradientWrapper> getGradientForFunction(
        const std::shared_ptr<FunctionWrapper>&) override;
private:
    FunctionsFactory(const std::shared_ptr<IApplicationStorage>&);
    std::map<std::string,std::shared_ptr<FunctionWrapper>> _functions;
    std::shared_ptr<IApplicationStorage> _applicationStorage;
    ParserWrapper _parser;
    Logger& _log;

    static std::shared_ptr<FunctionsFactory> _instance;
    static std::once_flag _onceFlag;
};

#endif //SOLVER_FUNCTIONGETTER_HPP
