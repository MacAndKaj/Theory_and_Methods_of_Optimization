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

class FunctionWrapper;
class GradientWrapper;

class PolakRibiereMethod : public IMethod
{
    IMETHODS_FRIENDSHIP
public:
    SSolution getSolution() const override;

    PolakRibiereMethod() = delete;
    PolakRibiereMethod(const PolakRibiereMethod&) = delete;

    void startComputing() override;
    void setCallbackWhenIterationDone(const std::function<void()>&);
    void setFunction(const std::shared_ptr<FunctionWrapper>&) override;
private:
    PolakRibiereMethod(const IterationMethodsParameters&, const std::vector<SVector>& solutionVecor);

//--stop condition checking
    bool isStopConditionFulfilled() const;
    void updateParameters();
    float getLastStepSize() const;
    float getErrorInCurrentPoint() const;
    float getLastStepFunctionDifference() const;
    unsigned int getCurrentIteration() const;

    /// Main optimization function iterating to find a solution
    /// \return Returns true if succesfully done, false otherwise
    bool optimizationOngoing(SVector&);
    void problemSolved();


    unsigned int _currentIteration;
    SVector _currentGradient;

//--solution _trace including [x_0,x_1,...,x_n -> x_d]
    std::function<void()> _callback;
    std::vector<SVector> _solutionVecor;
    std::shared_ptr<FunctionWrapper> _function;
    std::shared_ptr<GradientWrapper> _gradient;
    IterationMethodsParameters _parameters;
    Logger& _log;
};

#endif //SOLVER_POLAKRIBIEREMETHOD_HPP
