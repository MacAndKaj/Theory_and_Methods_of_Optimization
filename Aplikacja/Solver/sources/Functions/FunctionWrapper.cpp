//
// Created by maciek on 19.03.19.
//

#include <Functions/FunctionWrapper.hpp>
#include <SVector.hpp>
#include <iostream>
#include <Logger/LoggersFactory.hpp>

FunctionWrapper::FunctionWrapper()
    : _log(LoggersFactory::getLoggersFactory().getLogger("FunctionWrapper"))
{

}

void FunctionWrapper::addSymbols(const std::vector<std::pair<std::string, float>>& namesAndValuesMap)
{
    std::for_each(namesAndValuesMap.begin(), namesAndValuesMap.end(), [&](auto nameValuePair){
        _symbols.emplace_back(nameValuePair.second);
    });

    auto symbolIterator = _symbols.begin();
    for (const auto& nameAndValue : namesAndValuesMap)
    {
        _symbolTable.add_variable(nameAndValue.first, *symbolIterator);
        symbolIterator++;
    }
}

exprtk::expression<float>& FunctionWrapper::configAndGetExpression(const std::string& exprStr)
{
    _expressionString = exprStr;
    _expression.register_symbol_table(_symbolTable);
    return _expression;
}

std::optional<float> FunctionWrapper::operator ()(SVector& point)
{
    if (point.getSize() != _symbols.size()) return std::optional<float>();

    auto pointIterator = point.getVector().cbegin();
    for (auto&& symbol : _symbols)
    {
        symbol = *pointIterator;
        pointIterator++;
    }
    return std::optional<float>(_expression.value());
}

const std::string FunctionWrapper::getExpressionString() const
{
    return _expressionString;
}

