//
// Created by maciek on 02.04.19.
//

#include "ApplicationStorage.hpp"
#include <Methods/MethodsFactory.hpp>
#include <Functions/FunctionsFactory.hpp>
#include <SymbolicOperations/SymbolicOperator.hpp>

const std::shared_ptr<IMethodsFactory>& ApplicationStorage::getMethodsFactory()
{
    if (not _methodsFactory)
    {
        _methodsFactory = MethodsFactory::getInstance();
    }
    return _methodsFactory;
}

const std::shared_ptr<IFunctionsFactory>& ApplicationStorage::getFunctionsFactory()
{

    if (not _functionsFactory)
    {
        _functionsFactory = FunctionsFactory::getInstance();
    }
    return _functionsFactory;
}

const std::shared_ptr<ISymbolicOperator>& ApplicationStorage::getSymbolicOperator()
{

    if (not _symbolicOperator)
    {
        _symbolicOperator = SymbolicOperator::getInstance(shared_from_this());
    }
    return _symbolicOperator;
}
