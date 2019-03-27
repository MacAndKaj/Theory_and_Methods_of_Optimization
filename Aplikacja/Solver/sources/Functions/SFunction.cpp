//
// Created by maciek on 16.03.19.
//

#include <Functions/SFunction.hpp>
#include <SVector.hpp>
#include <Logger/LoggersFactory.hpp>

SFunction::SFunction(unsigned int& dimension, const std::function<float(SVector&)>& func)
    : _dimension(dimension)
    , _func(func)
    , _log(LoggersFactory::getLoggersFactory().getLogger("SFunction"))
{

}

std::optional<float> SFunction::operator ()(SVector& point) const
{
    std::optional<float> result;
    if (point.getSize() != _dimension)
    {
        _log << std::string(__FUNCTION__) + "Computing value of function in point " +
                point.toString();
        return result;
    }
    _log << "Computing value of function in point " + point.toString();
    result = _func(point);
    return result;
}

unsigned int SFunction::getDimension() const
{
    return _dimension;
}
