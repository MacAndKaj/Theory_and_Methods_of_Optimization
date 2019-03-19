//
// Created by maciek on 19.03.19.
//

#include <FunctionGetter/ParserWrapper.hpp>

std::shared_ptr<FunctionWrapper>
ParserWrapper::parseToFunction(unsigned int dimension, const std::string& expr)
{
    auto wrapper = std::make_shared<FunctionWrapper>();
    for (auto i = 1; i <= dimension; ++i)
    {
        auto tempVar = "x" + std::to_string(i);
        wrapper->addSymbol(tempVar);
    }

    _parser.compile(expr, wrapper->configAndGetExpression());
    return wrapper;
}

ParserWrapper::ParserWrapper()
{

}
