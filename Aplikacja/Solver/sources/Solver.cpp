//
// Created by maciek on 06.03.19.
//
#include <Solver.hpp>
#include <Methods/PolakRibiereMethod.hpp>

Solver::Solver(const std::shared_ptr<IApplicationStorage>& applicationStorage)
    : _methodType(MethodType::MethodType_Unknown)
    , _log(LoggersFactory::getLoggersFactory().getLogger("Solver"))
{
    _applicationStorage = applicationStorage;
    _log << "Generating Solver";
}

void Solver::setMethod(MethodType methodType)
{
    _methodType = methodType;
    if (_methodType == MethodType::MethodType_PolakRibiere)
    {
        std::stringstream strm;
        strm << "[" << __FUNCTION__ << "] to: " << methodType;
        _log << strm.str();
    }
    else
    {

    }
}

void Solver::computeSolution()
{
    if(not _method)
    {
        _log << "["+std::string(__FUNCTION__) + "] WARNING! Method not set, returning!";
        return;
    }
//    std::thread computingThread(&PolakRibiereMethod::startComputing,*_method);
}

SSolution Solver::getSolution() const
{
    return SSolution();
}

void Solver::setFunction(const unsigned int& dimension, const std::string& function)
{
    if (not _method)
    {
        std::stringstream strm;
        strm << "[" << __FUNCTION__ << "]Method not set! Function " << function << " not set! Returning...";
        _log << strm.str();
        return;
    }
    auto functionWrapper = _functionsFactory->getFunctionFromString(function, dimension);
    _method->setFunction(functionWrapper);
}

void Solver::setAlgorithmParameters()
{

}

bool Solver::isComplete() const
{
    return _methodType != MethodType::MethodType_Unknown and _method;
}

