//
// Created by maciek on 23.03.19.
//

#ifndef SOLVER_SYMBOLICOPERATOR_HPP
#define SOLVER_SYMBOLICOPERATOR_HPP

#include <string>
#include <mutex>
#include "PythonFileHelper.hpp"
#include "ISymbolicOperator.hpp"

class Logger;
class IFunctionsFactory;
class IApplicationStorage;

class SymbolicOperator : public ISymbolicOperator
{
public:
    SymbolicOperator(const SymbolicOperator&) = delete;
    static const std::shared_ptr<ISymbolicOperator> getInstance(const std::shared_ptr<IApplicationStorage>&);

    GradientVector getDerivatives(std::shared_ptr<FunctionWrapper>&) const override;
private:
    explicit SymbolicOperator(const std::shared_ptr<IApplicationStorage>&);
    GradientVector readFromFile(std::string&, std::shared_ptr<FunctionWrapper>&) const;

    PythonFileHelper _pythonFileHelper;
    std::shared_ptr<IFunctionsFactory> _functionsFactory;

    Logger& _log;

    static std::shared_ptr<SymbolicOperator> _instance;
    static std::once_flag _onceFlag;
};

#endif //SOLVER_SYMBOLICOPERATOR_HPP
