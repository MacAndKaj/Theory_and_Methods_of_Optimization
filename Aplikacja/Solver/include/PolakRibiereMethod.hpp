//
// Created by maciek on 08.03.19.
//

#ifndef SOLVER_POLAKRIBIEREMETHOD_HPP
#define SOLVER_POLAKRIBIEREMETHOD_HPP

#include <bits/unique_ptr.h>
#include <Logger/Logger.hpp>
#include "SVector.hpp"
#include "Interface/IMethod.hpp"

class SObjectiveFunction;

class PolakRibiereMethod : public IMethod
{
    IMETHODS_FRIENDSHIP
public:
    SSolution getSolution() const override;

    PolakRibiereMethod() = delete;
    PolakRibiereMethod(const PolakRibiereMethod&) = delete;

    void startComputing() override;
    void setFunction(std::unique_ptr<SObjectiveFunction>&) override;
private:
    PolakRibiereMethod(float error, float minimalStepBetweenTwoPoints, float minimalDifferenceBetweenStepsValues,
        unsigned int numberOfIterations, const std::vector<SVector>& solutionVecor);
    float getBeta() const;
    SVector getGradientInCurrentPoint() const;

//--stop condition checking
    bool isStopConditionFulfilled() const;
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
    std::vector<SVector> _solutionVecor;
    std::unique_ptr<SObjectiveFunction> _function;
    Logger& _log;
};

#endif //SOLVER_POLAKRIBIEREMETHOD_HPP
