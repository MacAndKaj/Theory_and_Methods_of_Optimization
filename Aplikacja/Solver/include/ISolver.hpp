//
// Created by maciek on 06.03.19.
//

#ifndef SOLVER_ISOLVER_HPP
#define SOLVER_ISOLVER_HPP

#include <string>
#include <functional>
#include <Definitions_and_Helpers/Definitions.hpp>
#include <Methods/IterationMethodsParameters.hpp>

class SSolution;
class SVector;
class FunctionInPointParameters;
class FunctionWrapper;

class ISolver
{
public:
    virtual void setMethod(MethodType) = 0;
    virtual void setStartingPoint(const SVector&) = 0;
    virtual void setAlgorithmParameters(const IterationMethodsParameters&) = 0;
    virtual void setFunction(const unsigned int&,const std::string&) = 0;
    virtual bool computeSolution(const std::function<void(FunctionInPointParameters)>&) = 0;
    virtual SSolution getSolution() const = 0;
    virtual std::shared_ptr<FunctionWrapper> getFunction() const = 0;
};

#endif //SOLVER_ISOLVER_HPP
