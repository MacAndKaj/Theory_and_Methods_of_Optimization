//
// Created by maciek on 06.03.19.
//

#ifndef SOLVER__SOLVER_HPP
#define SOLVER__SOLVER_HPP


#include <memory>
#include <Logger/LoggersFactory.hpp>
#include "ISolver.hpp"
#include <Functions/FunctionsFactory.hpp>
#include <Methods/IterationMethodsParameters.hpp>

class IMethod;
class IApplicationStorage;

class Solver: public ISolver
{
public:
    Solver() = delete;
    explicit Solver(const std::shared_ptr<IApplicationStorage>&);
    bool computeSolution(const std::function<void(FunctionInPointParameters)>& callback) override;

    SSolution getSolution() const override;
    std::shared_ptr<FunctionWrapper> getFunction() const override;

    void setAlgorithmParameters(const IterationMethodsParameters&) override;
    void setMethod(MethodType) override;
    void setFunction(const unsigned int&,const std::string&) override;
    void setStartingPoint(const SVector& vector) override;
private:

    MethodType _methodType;
    std::shared_ptr<IMethod> _method;
    std::shared_ptr<IFunctionsFactory> _functionsFactory;
    IterationMethodsParameters _parameters;
    unsigned int _dimension;
    std::string _function;
    Logger& _log;

    std::shared_ptr<SSolution> _solution;
    std::shared_ptr<IApplicationStorage> _applicationStorage;
};

#endif //SOLVERTESTS_SOLVER_HPP
