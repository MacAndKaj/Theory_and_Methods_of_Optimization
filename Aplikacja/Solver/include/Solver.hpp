//
// Created by maciek on 06.03.19.
//

#ifndef SOLVER__SOLVER_HPP
#define SOLVER__SOLVER_HPP


#include <bits/unique_ptr.h>
#include "Definitions_and_Helpers/Definitions.hpp"
#include "Interface/ISolver.hpp"

class IMethod;

class Solver: public ISolver
{
public:
    Solver();
    void setMethod(MethodType) override;

    void computeSolution() const override;
    SSolution getSolution() const override;
private:
    MethodType _methodType;
    std::unique_ptr<IMethod> _method;
};

#endif //SOLVERTESTS_SOLVER_HPP
