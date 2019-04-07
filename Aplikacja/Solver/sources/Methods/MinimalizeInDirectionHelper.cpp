//
// Created by maciek on 07.04.19.
//

#include <Methods/MinimalizeInDirectionHelper.hpp>
#include <Logger/LoggersFactory.hpp>

MinimalizeInDirectionHelper::MinimalizeInDirectionHelper()
    : _log(LoggersFactory::getLoggersFactory().getLogger("MinimalizationHelper"))
{

}

MinimalizeInDirectionHelper::MinimalizeInDirectionHelper(
    const std::shared_ptr<FunctionWrapper>& functionWrapper)
    : _functionWrapper(functionWrapper)
    , _log(LoggersFactory::getLoggersFactory().getLogger("MinimalizationHelper"))
{

}

void MinimalizeInDirectionHelper::setFunctionWrapper(
    const std::shared_ptr<FunctionWrapper>& functionWrapper)
{
    _functionWrapper = functionWrapper;
}


/// Method helping to minimalize function in direction starting from point.
/// \param direction - Direction along which function will be minimalized.
/// \param point - Starting point.
/// \return beta coefficient
float MinimalizeInDirectionHelper::getAlfa(const SVector& direction, const SVector& point) const
{
    return 0;
}

