//
// Created by maciek on 02.04.19.
//

#ifndef SOLVER_APPLICATIONSTORAGE_HPP
#define SOLVER_APPLICATIONSTORAGE_HPP

#include "IApplicationStorage.hpp"

class ApplicationStorage : public IApplicationStorage
    , public std::enable_shared_from_this<IApplicationStorage>
{
public:
    ApplicationStorage() = default;
    const std::shared_ptr<IMethodsFactory>& getMethodsFactory() override;
    const std::shared_ptr<IFunctionsFactory>& getFunctionsFactory() override;
    const std::shared_ptr<ISymbolicOperator>& getSymbolicOperator() override;
private:
    std::shared_ptr<IMethodsFactory> _methodsFactory;
    std::shared_ptr<IFunctionsFactory> _functionsFactory;
    std::shared_ptr<ISymbolicOperator> _symbolicOperator;
};

#endif //SOLVER_APPLICATIONSTORAGE_HPP
