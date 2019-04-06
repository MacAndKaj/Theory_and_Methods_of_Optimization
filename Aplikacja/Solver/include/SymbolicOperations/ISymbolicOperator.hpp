//
// Created by maciek on 02.04.19.
//

#ifndef SOLVER_ISYMBOLICOPERATOR_HPP
#define SOLVER_ISYMBOLICOPERATOR_HPP

#include <memory>
#include <vector>


class FunctionWrapper;

using GradientVector = std::vector<std::shared_ptr<FunctionWrapper>>;

class ISymbolicOperator
{
public:
    virtual GradientVector getDerivatives(const std::shared_ptr<FunctionWrapper>&) const = 0;
};

#endif //SOLVER_ISYMBOLICOPERATOR_HPP
