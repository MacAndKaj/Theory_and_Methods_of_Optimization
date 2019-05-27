//
// Created by maciek on 03.04.19.
//

#ifndef SOLVER_ITERATIONMETHODSPARAMETERS_HPP
#define SOLVER_ITERATIONMETHODSPARAMETERS_HPP

class IterationMethodsParameters
{
public:
    IterationMethodsParameters();
    IterationMethodsParameters(const double& error, const double& minimalStepSize,
        const double& minimalStepFunctionDifference, const double& armijoParameter, unsigned int maxNumberOfIterations);
    IterationMethodsParameters(const IterationMethodsParameters&) = default;
    IterationMethodsParameters& operator =(const IterationMethodsParameters&) = default;

    const double getError() const;
    const double getMinimalStepSize() const;
    const double getMinimalStepFunctionDifference() const;
    const unsigned int getMaxNumberOfIterations() const;
    const double getArmijoMethodParameter() const;
private:
    double _error;
    double _minimalStepSize;
    double _minimalStepFunctionDifference;
    double _armijoMethodParameter;
    unsigned int _maxNumberOfIterations;
};

#endif //SOLVER_ITERATIONMETHODSPARAMETERS_HPP
