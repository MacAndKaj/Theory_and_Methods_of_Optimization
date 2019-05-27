//
// Created by maciek on 08.03.19.
//

#ifndef SOLVER_POLAKRIBIEREMETHOD_HPP
#define SOLVER_POLAKRIBIEREMETHOD_HPP

#include <memory>
#include <Logger/Logger.hpp>
#include <SVector.hpp>
#include "IMethod.hpp"
#include "IterationMethodsParameters.hpp"
#include "MinimalizeInDirectionHelper.hpp"

class FunctionWrapper;
class GradientWrapper;
class FunctionInPointParameters;

class PolakRibiereMethod : public IMethod
{
    IMETHODS_FRIENDSHIP
public:
    SSolution getSolution() const override;

    PolakRibiereMethod() = delete;
    PolakRibiereMethod(const PolakRibiereMethod&) = delete;

    bool startComputing() override;
    void setCallbackWhenIterationDone(const std::function<void(FunctionInPointParameters)>&) override;

    void setGradient(const std::shared_ptr<GradientWrapper>&) override;
    void setFunction(const std::shared_ptr<FunctionWrapper>&) override;
    void setHessian(const std::shared_ptr<HessianWrapper>& hessian) override;

    bool isReadyToCompute() const override;
private:
    PolakRibiereMethod(const IterationMethodsParameters&, std::shared_ptr<SSolution>);

//--stop condition checking
    bool isStopConditionFulfilled() const;
    double getLastStepSize() const;
    double getErrorInCurrentPoint() const;
    double getLastStepFunctionDifference() const;
    unsigned int getCurrentIteration() const;

    /// Main optimization function iterating to find a solution
    /// \return Returns true if succesfully done, false otherwise
    bool optimizationOngoing();
    double getBeta(const SVector&, const SVector&) const;
    void problemSolved();

    unsigned int _currentIteration;

//--solution _trace including [x_0,x_1,...,x_n -> x_d]
    std::function<void(FunctionInPointParameters)> _callback;
    std::shared_ptr<SSolution> _solutionVector;
    std::shared_ptr<FunctionWrapper> _function;
    std::shared_ptr<GradientWrapper> _gradient;
    std::shared_ptr<HessianWrapper> _hessian;
    IterationMethodsParameters _parameters;
    MinimalizeInDirectionHelper _minimalizeInDirectionHelper;
    Logger& _log;
};

#endif //SOLVER_POLAKRIBIEREMETHOD_HPP
