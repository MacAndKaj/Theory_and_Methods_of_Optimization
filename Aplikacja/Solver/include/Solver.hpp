//
// Created by maciek on 06.03.19.
//

#ifndef SOLVER__SOLVER_HPP
#define SOLVER__SOLVER_HPP


#include <memory>
#include <Logger/LoggersFactory.hpp>
#include "ISolver.hpp"
#include <Functions/FunctionsFactory.hpp>
#include <Solver/include/Methods/IterationMethodsParameters.hpp>

class IMethod;
class IApplicationStorage;

class Solver: public ISolver
{
public:
    Solver() = delete;
    explicit Solver(const std::shared_ptr<IApplicationStorage>&);
    void computeSolution() override;

    SSolution getSolution() const override;

    void setAlgorithmParameters(const IterationMethodsParameters&) override;
    void setMethod(MethodType) override;
    void setFunction(const unsigned int&,const std::string&) override;

    bool isComplete() const override;
private:
    MethodType _methodType;
    std::shared_ptr<IMethod> _method;
    std::shared_ptr<IFunctionsFactory> _functionsFactory;
    Logger& _log;
    std::shared_ptr<IApplicationStorage> _applicationStorage;
};

#endif //SOLVERTESTS_SOLVER_HPP
