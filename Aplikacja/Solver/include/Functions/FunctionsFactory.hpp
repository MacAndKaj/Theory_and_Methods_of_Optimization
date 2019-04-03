//
// Created by maciek on 19.03.19.
//

#ifndef SOLVER_FUNCTIONGETTER_HPP
#define SOLVER_FUNCTIONGETTER_HPP

#include <Functions/IFunctionsFactory.hpp>
#include "ParserWrapper.hpp"

class ParserWrapper;
class ApplicationStorage;

class FunctionsFactory : public IFunctionsFactory
{
public:
    static const std::shared_ptr<IFunctionsFactory> getInstance();
    std::shared_ptr<FunctionWrapper> parseStringToSFunction(const std::string&, unsigned int) override;
private:
    FunctionsFactory();

    ParserWrapper _parser;
    Logger& _log;

    static std::shared_ptr<FunctionsFactory> _instance;
    static std::once_flag _onceFlag;
};

#endif //SOLVER_FUNCTIONGETTER_HPP
