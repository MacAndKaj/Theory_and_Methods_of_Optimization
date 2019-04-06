//
// Created by maciek on 06.04.19.
//

#include <Functions/HessianWrapper.hpp>
#include <SMatrix.hpp>
#include <Logger/LoggersFactory.hpp>

HessianWrapper::HessianWrapper(const std::shared_ptr<GradientWrapper>& gradient,
    const std::shared_ptr<IApplicationStorage>& applicationStorage)
    : _log(LoggersFactory::getLoggersFactory()
               .getLogger("HessianWrapper[" + gradient->getOriginalFunction() + "]"))
{

}

std::optional <SMatrix> HessianWrapper::getHessianInPoint(const SVector&)
{
    return {};
}
