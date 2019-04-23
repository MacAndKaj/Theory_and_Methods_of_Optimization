//
// Created by maciek on 03.04.19.
//

#ifndef SOLVER_ITERATIONMETHODSPARAMETERS_HPP
#define SOLVER_ITERATIONMETHODSPARAMETERS_HPP

class IterationMethodsParameters
{
public:
    IterationMethodsParameters(double error, double minimalStepSize,
        double minimalStepFunctionDifference, unsigned int maxNumberOfIterations);
    IterationMethodsParameters(const IterationMethodsParameters&);

    bool isComplete() const;
    const double getError() const;
    const double getMinimalStepSize() const;
    const double getMinimalStepFunctionDifference() const;
    const unsigned int getMaxNumberOfIterations() const;
private:
    const double _error;
    const double _minimalStepSize;
    const double _minimalStepFunctionDifference;
    const unsigned int _maxNumberOfIterations;
};

#endif //SOLVER_ITERATIONMETHODSPARAMETERS_HPP
