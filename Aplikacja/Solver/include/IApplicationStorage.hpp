//
// Created by maciek on 02.04.19.
//

#ifndef SOLVER_IAPPLICATIONSTORAGE_HPP
#define SOLVER_IAPPLICATIONSTORAGE_HPP

#include <memory>

class IMethodsFactory;
class IFunctionsFactory;
class ISymbolicOperator;

class IApplicationStorage
{
public:
    virtual const std::shared_ptr<IMethodsFactory>& getMethodsFactory() = 0;
    virtual const std::shared_ptr<IFunctionsFactory>& getFunctionsFactory() = 0;
    virtual const std::shared_ptr<ISymbolicOperator>& getSymbolicOperator() = 0;
};

#endif //SOLVER_IAPPLICATIONSTORAGE_HPP
