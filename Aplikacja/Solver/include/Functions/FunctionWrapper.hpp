//
// Created by maciek on 19.03.19.
//

#ifndef SOLVER_FUNCTIONWRAPPER_HPP
#define SOLVER_FUNCTIONWRAPPER_HPP

#include <memory>
#include <functional>
#include <FunctionGetter/Parser/exprtk.hpp>

class SVector;

class FunctionWrapper
{
public:
    FunctionWrapper() = default;

    void addSymbol(const std::string&);
    exprtk::expression<float>& configAndGetExpression();
    std::optional<float> operator()(SVector&);

private:
    std::vector<float> _symbols;
    exprtk::symbol_table<float> _symbolTable;
    exprtk::expression<float> _expression;
};

#endif //SOLVER_FUNCTIONWRAPPER_HPP
