//
// Created by maciek on 08.03.19.
//

#ifndef SOLVER_IMETHOD_HPP
#define SOLVER_IMETHOD_HPP

#include "SSolution.hpp"

#define IMETHODS_FRIENDSHIP friend class MethodsFactory;
class FunctionWrapper;
class GradientWrapper;
class HessianWrapper;
class FunctionInPointParameters;

class IMethod
{
public:
    virtual bool startComputing() = 0;
    virtual void setCallbackWhenIterationDone(
        const std::function<void(FunctionInPointParameters)>& callback) = 0;
    virtual void setFunction(const std::shared_ptr<FunctionWrapper>&) = 0;
    virtual void setGradient(const std::shared_ptr<GradientWrapper>&) = 0;
    virtual void setHessian(const std::shared_ptr<HessianWrapper>&) = 0;
    virtual bool isReadyToCompute() const = 0;
    virtual SSolution getSolution() const = 0;
};

#endif //SOLVER_IMETHOD_HPP
