//
// Created by maciek on 08.03.19.
//

#ifndef SOLVER_POLAKRIBIEREMETHOD_HPP
#define SOLVER_POLAKRIBIEREMETHOD_HPP

#include <bits/unique_ptr.h>
#include <Logger/Logger.hpp>
#include <SVector.hpp>
#include "IMethod.hpp"

class FunctionWrapper;

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
    PolakRibiereMethod(float error, float minimalStepBetweenTwoPoints, float minimalDifferenceBetweenStepsValues,
        unsigned int numberOfIterations, const std::vector<SVector>& solutionVecor);

//--stop condition checking
    bool isStopConditionFulfilled() const;
    void updateParameters();
    float getLastStepSize() const;
    float getErrorInCurrentPoint() const;
    float getLastStepFunctionDifference() const;
    unsigned int getCurrentIteration() const;

//--Algorithm parameters
    float _error;
    float _minimalStepSize;
    float _minimalStepFunctionDifference;
    unsigned int _maxNumberOfIterations;
    unsigned int _currentIteration;

//--solution _trace including [x_0,x_1,...,x_n -> x_d]
    std::function<void()> _callback;
    std::vector<SVector> _solutionVecor;
    std::shared_ptr<FunctionWrapper> _function;
    Logger& _log;
};

#endif //SOLVER_POLAKRIBIEREMETHOD_HPP
