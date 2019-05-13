//
// Created by maciek on 23.04.19.
//

#include <Polak_Ribiere/include/SolverWrapper.h>
#include <Solver/include/FunctionInPointParameters.hpp>
#include <Solver/include/Methods/IterationMethodsParameters.hpp>
#include <SSolution.hpp>

SolverWrapper::SolverWrapper()
    : _dimension(0)
{
    _applicationStorage = std::make_shared<ApplicationStorage>();
    _solver = std::make_unique<Solver>(_applicationStorage);
}

void SolverWrapper::setFunction(unsigned int dimension, const std::string& function)
{
    _dimension = dimension;
    _solver->setFunction(dimension, function);
}

void SolverWrapper::setMethod(MethodType methodType)
{
    _solver->setMethod(methodType);
}

void SolverWrapper::setAlgorithmParameters(const IterationMethodsParameters& params)
{
    _solver->setAlgorithmParameters(params);
}

void SolverWrapper::startComputing()
{
    _solver->computeSolution(
        [this](FunctionInPointParameters parameters){ emit iterationDone(parameters); });
}

void SolverWrapper::setStartPoint(const SVector& sVector)
{
    _solver->setStartingPoint(sVector);
}

SSolution SolverWrapper::getSolution() const
{
    return _solver->getSolution();
}

unsigned int SolverWrapper::getProblemDimension()const
{
    return _dimension;
}


std::shared_ptr<FunctionWrapper> SolverWrapper::getFunction() const
{
    return _solver->getFunction();
}

