//
// Created by maciek on 03.04.19.
//

#ifndef SOLVER_ITERATIONMETHODSPARAMETERS_HPP
#define SOLVER_ITERATIONMETHODSPARAMETERS_HPP

class IterationMethodsParameters
{
public:
    IterationMethodsParameters(float error, float minimalStepSize,
        float minimalStepFunctionDifference, unsigned int maxNumberOfIterations);
    const float getError() const;
    const float getMinimalStepSize() const;
    const float getMinimalStepFunctionDifference() const;
    const unsigned int getMaxNumberOfIterations() const;
private:
    const float _error;
    const float _minimalStepSize;
    const float _minimalStepFunctionDifference;
    const unsigned int _maxNumberOfIterations;
};

#endif //SOLVER_ITERATIONMETHODSPARAMETERS_HPP
