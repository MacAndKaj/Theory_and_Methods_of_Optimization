//
// Created by maciek on 23.04.19.
//

#include <Solver/include/FunctionInPointParameters.hpp>

#include "FunctionInPointParameters.hpp"

FunctionInPointParameters::FunctionInPointParameters(const SVector& point,
    const double functionValue)
    : _point(point)
    , _functionValue(functionValue)
{

}

const SVector& FunctionInPointParameters::getPoint() const
{
    return _point;
}

const double FunctionInPointParameters::getFunctionValue() const
{
    return _functionValue;
}

const std::string FunctionInPointParameters::toString() const
{
    return std::string("f(")+ _point.toString() + " = " + std::to_string(_functionValue);
}
