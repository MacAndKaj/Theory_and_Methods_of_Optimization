//
// Created by maciek on 07.04.19.
//

#ifndef SOLVER_MINIMALIZERINDIRECTION_HPP
#define SOLVER_MINIMALIZERINDIRECTION_HPP

#include <memory>
#include <Methods/IterationMethodsParameters.hpp>

class FunctionWrapper;
class GradientWrapper;
class SVector;
class Logger;


///Based on Armijo's rule for minimalization in direction
class MinimalizeInDirectionHelper
{
public:
    MinimalizeInDirectionHelper();
    MinimalizeInDirectionHelper(const std::shared_ptr<FunctionWrapper>&,
        const std::shared_ptr<GradientWrapper>&, double minStepSize);
    void setFunctionWrapper(const std::shared_ptr<FunctionWrapper>&);
    void setGradientWrapper(const std::shared_ptr<GradientWrapper>&);
    void setMinStepSize(double minStepSize);
    double getAlfa(const SVector&, const SVector&);
private:
    double _minStepSize{1e-5};

    std::shared_ptr<FunctionWrapper> _functionWrapper;
    std::shared_ptr<GradientWrapper> _gradientWrapper;
    Logger& _log;
};

#endif //SOLVER_MINIMALIZERINDIRECTION_HPP
