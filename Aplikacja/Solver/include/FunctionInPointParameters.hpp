//
// Created by maciek on 23.04.19.
//

#ifndef SOLVER_FUNCTIONINPOINTPARAMETERS_HPP
#define SOLVER_FUNCTIONINPOINTPARAMETERS_HPP

#include "SVector.hpp"


class FunctionInPointParameters
{
public:
    FunctionInPointParameters(const SVector& point, const double functionValue);
    FunctionInPointParameters() = delete;

    const SVector& getPoint() const;
    const double getFunctionValue() const;

    const std::string toString() const;
private:
    const SVector _point;
    const double _functionValue;
};

#endif //SOLVER_FUNCTIONINPOINTPARAMETERS_HPP
