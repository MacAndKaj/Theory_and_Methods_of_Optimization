//
// Created by maciek on 16.03.19.
//

#include <Functions/SGradient.hpp>
#include <SVector.hpp>
#include <Logger/LoggersFactory.hpp>

SGradient::SGradient(const std::vector<Function>& gradientVector)
    : _gradientVector(gradientVector)
    , _log(LoggersFactory::getLoggersFactory().getLogger("SGradient"))
{

}

Optional<SVector> SGradient::operator()(SVector& point) const
{
    Optional<SVector> result;
    if (point.getSize() != _dimension) return result;
    _log << std::string(__FUNCTION__) + "| Computing gradient vector in point" + point.toString();
    std::vector<float> gradient;
    for (auto&& func : _gradientVector)
    {
        gradient.emplace_back(func(point));
    }
    result = SVector(gradient);
    return result;
}
