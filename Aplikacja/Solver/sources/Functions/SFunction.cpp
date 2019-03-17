//
// Created by maciek on 16.03.19.
//

#include <Functions/SFunction.hpp>
#include <SVector.hpp>
#include <Definitions_and_Helpers/Optional.hpp>
#include <Logger/LoggersFactory.hpp>

SFunction::SFunction(unsigned int& dimension, const std::function<float(SVector&)>& func)
    : _dimension(dimension)
    , _func(func)
    , _log(LoggersFactory::getLoggersFactory().getLogger("SFunction"))
{

}

Optional<float> SFunction::operator ()(SVector& point) const
{
    Optional<float> result;
    if (point.getSize() != _dimension) return result;
    _log << std::string(__FUNCTION__) + " computing value of function in point " + point.toString();
    result = _func(point);
    return result;
}

unsigned int SFunction::getDimension() const
{
    return _dimension;
}

