//
// Created by maciek on 23.04.19.
//

#include <Polak_Ribiere/include/SolverWrapper.h>
#include <Solver/include/FunctionInPointParameters.hpp>
#include <Solver/include/Methods/IterationMethodsParameters.hpp>

SolverWrapper::SolverWrapper()
    : _iteration(0)
    , _log(LoggersFactory::getLoggersFactory().getLogger("SolverWrapper"))
{
    _applicationStorage = std::make_shared<ApplicationStorage>();
    _solver = std::make_unique<Solver>(_applicationStorage);
}

void SolverWrapper::iterationCallback(FunctionInPointParameters parameters)
{
    _log << 'I' + std::string(__FUNCTION__) + " In " + std::to_string(_iteration) +
            " iteration function is: " + parameters.toString();
    emit iterationDone(parameters);
}

void SolverWrapper::setFunction(unsigned int dimension, const std::string& function)
{
    _solver->setFunction(dimension, function);
}

void SolverWrapper::setMethod(MethodType methodType)
{
    _solver->setMethod(methodType);
}

void SolverWrapper::setAlgorithmParameters(const IterationMethodsParameters&)
{

}