//
// Created by maciek on 06.03.19.
//
#include <memory>
#include <Solver.hpp>
#include <Methods/PolakRibiereMethod.hpp>
#include <Methods/MethodsFactory.hpp>

Solver::Solver(const std::shared_ptr<IApplicationStorage>& applicationStorage)
    : _methodType(MethodType::MethodType_Unknown)
    , _log(LoggersFactory::getLoggersFactory().getLogger("Solver"))
{
    _applicationStorage = applicationStorage;
    _functionsFactory = applicationStorage->getFunctionsFactory();
    _log << "IGenerating Solver";
}

void Solver::setMethod(MethodType methodType)
{
    _methodType = methodType;
    if (_methodType == MethodType::MethodType_PolakRibiere)
    {
        std::stringstream strm;
        strm << "I[" << __FUNCTION__ << "] to: " << methodType;
        _log << strm.str();
    }
    else
    {
        std::stringstream strm;
        strm << "I[" << __FUNCTION__ << " Unknown method";
        _log << strm.str();
    }
}

void Solver::computeSolution(const std::function<void(FunctionInPointParameters)>& callback)
{
    if (_methodType == MethodType::MethodType_Unknown or not _solution)
    {
        _log << "E[" + std::string(__FUNCTION__) + "] WARNING! Method not set or lack of starting point, returning! ";
        return;
    }
    _method =
        _applicationStorage->getMethodsFactory()->getPolakRibiereMethod(
            _parameters.getError(), _parameters.getMinimalStepSize(), _parameters
                .getMinimalStepFunctionDifference(), _parameters.getArmijoMethodParameter()
            , _parameters.getMaxNumberOfIterations(), _solution);
    auto functionWrapper = _functionsFactory->getFunctionFromString(_function, _dimension);
    auto gradientWrapper = _functionsFactory->getGradientForFunction(functionWrapper);
    _method->setFunction(functionWrapper);
    _method->setGradient(gradientWrapper);
    _method->setCallbackWhenIterationDone(callback);
    _method->startComputing();
}

SSolution Solver::getSolution() const
{
    if(_method)
    {
        return _method->getSolution();
    }
    return SSolution({SVector()},0);
}

void Solver::setFunction(const unsigned int& dimension, const std::string& function)
{
    _function = function;
    _dimension = dimension;
}

void Solver::setAlgorithmParameters(const IterationMethodsParameters& parameters)
{
    if (_methodType == MethodType::MethodType_Unknown)
    {
        std::stringstream strm;
        strm << "E[" << __FUNCTION__ << "] Method is not set";
        _log << strm.str();
        return;
    }

    _parameters = parameters;
}

void Solver::setStartingPoint(const SVector& vector)
{
    auto startSolution = {vector};
    auto value =*getFunction()->operator()(vector);
    _solution = std::make_shared<SSolution>(startSolution,value);
}

std::shared_ptr<FunctionWrapper> Solver::getFunction() const
{
    return _functionsFactory->getFunctionFromString(_function,_dimension);
}
