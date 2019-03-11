//
// Created by maciek on 06.03.19.
//

#ifndef SOLVER__SOLVER_HPP
#define SOLVER__SOLVER_HPP

#include <bits/unique_ptr.h>
#include "PolakRibiereMethod.hpp"

class Solver
{
public:
    Solver();
private:
    std::unique_ptr<IMethod> _method;
};

#endif //SOLVERTESTS_SOLVER_HPP
