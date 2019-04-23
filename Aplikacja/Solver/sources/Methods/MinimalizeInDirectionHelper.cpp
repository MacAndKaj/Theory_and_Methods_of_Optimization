//
// Created by maciek on 07.04.19.
//

#include <Methods/MinimalizeInDirectionHelper.hpp>
#include <Functions/GradientWrapper.hpp>
#include <Logger/LoggersFactory.hpp>
#include <SVector.hpp>
#include <iostream>

MinimalizeInDirectionHelper::MinimalizeInDirectionHelper()
    : _log(LoggersFactory::getLoggersFactory().getLogger("MinimalizationHelper"))
{

}

MinimalizeInDirectionHelper::MinimalizeInDirectionHelper(
    const std::shared_ptr<FunctionWrapper>& functionWrapper,
    const std::shared_ptr<GradientWrapper>& gradientWrapper,
    double minStepSize)
    : _minStepSize(minStepSize)
    , _functionWrapper(functionWrapper)
    , _gradientWrapper(gradientWrapper)
    , _log(LoggersFactory::getLoggersFactory().getLogger("MinimalizationHelper"))
{
}

void MinimalizeInDirectionHelper::setFunctionWrapper(
    const std::shared_ptr<FunctionWrapper>& functionWrapper)
{
    _functionWrapper = functionWrapper;
}

void MinimalizeInDirectionHelper::setGradientWrapper(
    const std::shared_ptr<GradientWrapper>& gradientWrapper)
{
    _gradientWrapper = gradientWrapper;
}

/// Method helping to minimalize function in direction starting from point.
/// \param direction - Direction along which function will be minimalized.
/// \param point - Starting point.
/// \return beta coefficient
double MinimalizeInDirectionHelper::getAlfa(const SVector& direction, const SVector& point)
{
    if (not _functionWrapper or not _gradientWrapper)
    {
        _log << "[" + std::string(__FUNCTION__) + "]| Lack of function or its gradient!!!";
        return 0;
    }

    double alfa = 1;
    double beta = 0.1;
//    double s_random = 0.1;
//    auto current_gradient_point = (*_gradientWrapper->getGradientInPoint(point));
//    double s = ((*_gradientWrapper->getGradientInPoint(point))*s_random*s_random)/
//        (2*(*s_random+));
    double tau = 0.7;
    SVector next_point = point + alfa * direction;
    double value_in_x0 = *_functionWrapper->operator()(point);
    double value_in_next_point = *_functionWrapper->operator()(next_point);
    double stepSize = (next_point-point).getCartesianNorm();
    while (value_in_next_point >= value_in_x0 + alfa*beta*(*((*_gradientWrapper->getGradientInPoint(point)).transpose()*direction)) and stepSize > _minStepSize )
    {
        alfa = tau * alfa;
        next_point = next_point = point + alfa * direction;
        value_in_next_point = *_functionWrapper->operator()(next_point);
        stepSize = (next_point-point).getCartesianNorm();
    }
    _log << "[" + std::string(__FUNCTION__) + "] Alfa found in point " + point.toString() +
            " Is equal to " + std::to_string(alfa);

    return alfa;
}

void MinimalizeInDirectionHelper::setMinStepSize(double minStepSize)
{
    _minStepSize = minStepSize;
}



