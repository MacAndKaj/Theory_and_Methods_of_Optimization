//
// Created by maciek on 16.03.19.
//

#include <Functions/SHessian.hpp>
#include <Logger/LoggersFactory.hpp>
#include <SMatrix.hpp>

SHessian::SHessian(const std::vector<std::vector<SHessian::Function>>& hessianMatrix)
    : _hessianMatrix(hessianMatrix)
    , _log(LoggersFactory::getLoggersFactory().getLogger("SHessian"))
{

    if (not hessianMatrix.empty())
    {
        _dimension = {hessianMatrix.begin()->size(), hessianMatrix.size()};
    }
    else
    {
        _dimension = {0, 0};
    }
}

std::optional<SMatrix> SHessian::operator ()(SVector& point) const
{
    if (point.getSize() != _dimension.first)
    {
        _log << std::string(__FUNCTION__) + "| Wrong dimension of point!";
        return std::optional<SMatrix>();
    }
    _log << "| Computing hessian evaluation in point" + point.toString();
    std::vector<std::vector<float>> hessian;
    for (auto&& column : _hessianMatrix)
    {
        hessian.emplace_back();
        for (const auto& func : column)
        {
            (*hessian.rbegin()).emplace_back(func(point));
        }
    }
    return std::optional<SMatrix>(hessian);

}

const std::pair<unsigned int, unsigned int>& SHessian::getDimension() const
{
    return _dimension;
}
