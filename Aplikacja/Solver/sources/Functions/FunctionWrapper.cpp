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

void FunctionWrapper::addSymbols(const std::vector<std::pair<std::string, double>>& namesAndValuesMap)
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
    _log << "["+std::string(__FUNCTION__) + "] operation succedded!";
}

exprtk::expression<double>& FunctionWrapper::configAndGetExpression(const std::string& exprStr)
{
    _expressionString = exprStr;
    _expression.register_symbol_table(_symbolTable);
    return _expression;
}

std::optional<double> FunctionWrapper::operator()(const SVector& point)
{
    if (point.getSize() != _symbols.size()) {
        std::stringstream strm;
        strm << "| Computing value of function f(x)=" << _expressionString << " failed!";
        _log << strm.str();
        return std::optional<double>();
    }

    auto pointIterator = point.getVector().cbegin();
    for (auto&& symbol : _symbols)
    {
        symbol = *pointIterator;
        pointIterator++;
    }
    return std::optional<double>(_expression.value());
}

std::string FunctionWrapper::getExpressionString() const
{
    return _expressionString;
}

unsigned int FunctionWrapper::getDimension() const
{
    return static_cast<unsigned int>(_symbols.size());
}


