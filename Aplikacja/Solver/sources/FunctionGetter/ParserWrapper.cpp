//
// Created by maciek on 19.03.19.
//

#include <FunctionGetter/ParserWrapper.hpp>
#include <iostream>
#include <Logger/LoggersFactory.hpp>

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
        _log << "[" + std::string(__FUNCTION__) + "] | " + _parser.error() + " " +
                wrapper->getExpressionString();
    }

    return wrapper;
}

ParserWrapper::ParserWrapper()
    : _log(LoggersFactory::getLoggersFactory().getLogger("ParserWrapper"))
{

}
