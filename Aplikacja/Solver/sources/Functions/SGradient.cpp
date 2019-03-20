//
// Created by maciek on 16.03.19.
//

#include <Functions/SGradient.hpp>
#include <SVector.hpp>
#include <Logger/LoggersFactory.hpp>
#include <iostream>

SGradient::SGradient(const std::vector<Function>& gradientVector)
    : _dimension(static_cast<unsigned int>(gradientVector.size()))
    , _gradientVector(gradientVector)
    , _log(LoggersFactory::getLoggersFactory().getLogger("SGradient"))
{

}

std::optional<SVector> SGradient::operator ()(SVector& point) const
{
    if (point.getSize() != _dimension)
    {
        _log << std::string(__FUNCTION__) + "| Wrong dimension of point!";
        return std::optional<SVector>();
    }
    _log << "| Computing gradient vector in point" + point.toString();
    std::vector<float> gradient;
    for (auto&& func : _gradientVector)
    {
        gradient.emplace_back(func(point));
    }
    return std::optional<SVector>(gradient);
}
