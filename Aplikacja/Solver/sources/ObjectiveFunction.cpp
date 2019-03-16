//
// Created by maciek on 09.03.19.
//

#include <ObjectiveFunction.hpp>

#include "ObjectiveFunction.hpp"

ObjectiveFunction::ObjectiveFunction(unsigned int dimension, const std::function<float(SVector&)>& func)
    : _dimension(dimension)
    , _func(func)
{

}

ObjectiveFunction::ObjectiveFunction(unsigned int&& dimension, const std::function<float(SVector&)>& func)
    : _dimension(dimension)
    , _func(func)
{

}
float ObjectiveFunction::operator ()(SVector& point) const
{
    if(point.getSize() != _dimension) return 0;

    return _func(point);
}

