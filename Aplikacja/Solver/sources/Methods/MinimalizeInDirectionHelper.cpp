//
// Created by maciek on 07.04.19.
//

#include <Methods/MinimalizeInDirectionHelper.hpp>
#include <Functions/GradientWrapper.hpp>
#include <Logger/LoggersFactory.hpp>
#include <SVector.hpp>
#include <iostream>
#include <iomanip>

MinimalizeInDirectionHelper::MinimalizeInDirectionHelper()
    : _log(LoggersFactory::getLoggersFactory().getLogger("MinimalizationHelper"))
{

}

MinimalizeInDirectionHelper::MinimalizeInDirectionHelper(
    const std::shared_ptr<FunctionWrapper>& functionWrapper,
    const std::shared_ptr<GradientWrapper>& gradientWrapper,
    double minStepSize, double tau)
    : _minStepSize(minStepSize)
    , _tau(tau)
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

void MinimalizeInDirectionHelper::setMinStepSize(double minStepSize)
{
    _minStepSize = minStepSize;
}

void MinimalizeInDirectionHelper::setTau(double tau)
{
    _tau = tau;
}

/// Method helping to minimalize function in direction starting from point.
/// \param direction - Direction along which function will be minimalized.
/// \param point - Starting point.
/// \return beta coefficient
double MinimalizeInDirectionHelper::getAlfa(const SVector& direction, const SVector& point)
{
    if (not _functionWrapper or not _gradientWrapper)
    {
        _log << "E[" + std::string(__FUNCTION__) + "]| Lack of function or its gradient!!!";
        return 0;
    }

    double alfa = 1;
    double eta = 0.1;
    SVector next_point = point + alfa * direction;
    double value_in_x0 = *_functionWrapper->operator ()(point);
    double value_in_next_point = *_functionWrapper->operator ()(next_point);
    double stepSize = (next_point-point).getCartesianNorm();
    while (value_in_next_point >= value_in_x0 + alfa*eta*(*((*_gradientWrapper->getGradientInPoint(point)).transpose()*direction)) and stepSize > _minStepSize)
    {
        alfa = _tau * alfa;
        next_point = point + alfa * direction;
        value_in_next_point = *_functionWrapper->operator ()(next_point);
        stepSize = (next_point-point).getCartesianNorm();
    }

    std::stringstream strm;
    strm  << "I[" + std::string(__FUNCTION__) << "] Alfa found in point " << point.toString() +
             " Is equal to " << std::setprecision(20) << alfa;
    _log << strm.str();
    return alfa;
}

