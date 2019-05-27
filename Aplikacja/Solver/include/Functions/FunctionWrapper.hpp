//
// Created by maciek on 19.03.19.
//

#ifndef SOLVER_FUNCTIONWRAPPER_HPP
#define SOLVER_FUNCTIONWRAPPER_HPP

#include <memory>
#include <functional>
#include "Parser/exprtk.hpp"
#include <Logger/Logger.hpp>

class SVector;

class FunctionWrapper
{
public:
    FunctionWrapper();

    void addSymbols(const std::vector<std::pair<std::string, double>>&);
    exprtk::expression<double>& configAndGetExpression(const std::string&);
    std::optional<double> operator ()(const SVector&);
    std::string getExpressionString() const;
    unsigned int getDimension() const;

private:
    std::vector<double> _symbols;
    exprtk::symbol_table<double> _symbolTable;
    exprtk::expression<double> _expression;
    std::string _expressionString;
    Logger& _log;
};

#endif //SOLVER_FUNCTIONWRAPPER_HPP
