//
// Created by maciek on 19.03.19.
//

#include <Functions/FunctionWrapper.hpp>
#include <SVector.hpp>

void FunctionWrapper::addSymbol(const std::string& name)
{
    _symbols.emplace_back(0);
    _symbolTable.add_variable(name, _symbols.back());
}

exprtk::expression<float>& FunctionWrapper::configAndGetExpression()
{
    _expression.register_symbol_table(_symbolTable);
    return _expression;
}

std::optional<float> FunctionWrapper::operator ()(SVector& point)
{
    std::optional<float> result;
    if (point.getSize() != _symbols.size()) return result;

    auto symbolsIterator = _symbols.begin();
    for (const auto& x : point.getVector())
    {
        *symbolsIterator = x;
        symbolsIterator++;
    }
    return std::optional<float>(_expression.value());
}

