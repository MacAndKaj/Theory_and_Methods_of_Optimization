//
// Created by maciek on 19.03.19.
//

#include <Functions/ParserWrapper.hpp>
#include <iostream>
#include <Logger/LoggersFactory.hpp>

ParserWrapper::ParserWrapper()
    : _log(LoggersFactory::getLoggersFactory().getLogger("ParserWrapper"))
{

}

std::shared_ptr<FunctionWrapper>
ParserWrapper::parseToFunction(unsigned int dimension, const std::string& expr)
{
    auto wrapper = std::make_shared<FunctionWrapper>();
    std::vector<std::pair<std::string,float>> namesAndValues;
    for (auto i = 1; i <= dimension; ++i)
    {
        namesAndValues.emplace_back("x" + std::to_string(i),0.f);
    }
    wrapper->addSymbols(namesAndValues);
    if (not _parser.compile(expr, wrapper->configAndGetExpression(expr)))
    {
        _log << "[" + std::string(__FUNCTION__) + "]| Error! " + _parser.error() + " " +
                wrapper->getExpressionString();
    }
    std::stringstream strm;
    strm << "[" << __FUNCTION__ << "]| Succedded for function f(x)=" << expr;
    _log << strm.str();
    return wrapper;
}
