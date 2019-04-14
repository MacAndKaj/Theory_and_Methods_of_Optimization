//
// Created by maciek on 19.03.19.
//

#ifndef SOLVER_PARSERWRAPPER_HPP
#define SOLVER_PARSERWRAPPER_HPP

#include <Functions/FunctionWrapper.hpp>
#include <Logger/Logger.hpp>

class SVector;
class FunctionsFactory;

class ParserWrapper
{
public:
    ParserWrapper(const ParserWrapper&) = delete;
    ParserWrapper& operator =(const ParserWrapper&) = delete;

    std::shared_ptr<FunctionWrapper> parseToFunction(unsigned int, const std::string&);
protected:
    ParserWrapper();
    exprtk::parser<double> _parser;
    Logger& _log;

    friend class FunctionsFactory;
};

#endif //SOLVER_PARSERWRAPPER_HPP
