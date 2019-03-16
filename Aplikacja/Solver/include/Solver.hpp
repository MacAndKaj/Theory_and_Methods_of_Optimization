//
// Created by maciek on 06.03.19.
//

#ifndef SOLVER__SOLVER_HPP
#define SOLVER__SOLVER_HPP


#include <bits/unique_ptr.h>
#include "Definitions.hpp"
#include "ISolver.hpp"

class IMethod;

class Solver: public ISolver
{
public:
    Solver();
private:
    void setMethod(MethodType) override;

    void computeSolution() const override;
    SSolution getSolution() const override;
private:
    MethodType _methodType;
    std::unique_ptr<IMethod> _method;
};

#endif //SOLVERTESTS_SOLVER_HPP
