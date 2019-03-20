//
// Created by maciek on 19.03.19.
//

#ifndef SOLVER_FUNCTIONWRAPPER_HPP
#define SOLVER_FUNCTIONWRAPPER_HPP

#include <memory>
#include <functional>
#include <FunctionGetter/Parser/exprtk.hpp>
#include <Logger/Logger.hpp>

class SVector;

class FunctionWrapper
{
public:
    FunctionWrapper();

    void addSymbols(const std::vector<std::pair<std::string, float>>&);
    exprtk::expression<float>& configAndGetExpression(const std::string&);
    std::optional<float> operator()(SVector&);
    const std::string getExpressionString() const;

private:
    std::vector<float> _symbols;
    exprtk::symbol_table<float> _symbolTable;
    exprtk::expression<float> _expression;
    std::string _expressionString;
    Logger& _log;
};

#endif //SOLVER_FUNCTIONWRAPPER_HPP
