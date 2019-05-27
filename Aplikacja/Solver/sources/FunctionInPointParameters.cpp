//
// Created by maciek on 23.04.19.
//

#include <sstream>
#include <FunctionInPointParameters.hpp>

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
    std::stringstream strm;
    strm << "f(" <<  _point.toString()
        << ") = "<< _functionValue;

    return strm.str();
}
