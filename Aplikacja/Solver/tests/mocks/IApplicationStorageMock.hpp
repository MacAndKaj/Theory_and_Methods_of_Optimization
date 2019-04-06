//
// Created by maciek on 03.04.19.
//

#ifndef SOLVER_IAPPLICATIONSTORAGEMOCK_HPP
#define SOLVER_IAPPLICATIONSTORAGEMOCK_HPP

#include<gmock/gmock.h>
#include<IApplicationStorage.hpp>

class IApplicationStorageMock: public IApplicationStorage
{
public:
    MOCK_METHOD0(getMethodsFactory,const std::shared_ptr<IMethodsFactory>&());
    MOCK_METHOD0(getFunctionsFactory,const std::shared_ptr<IFunctionsFactory>&());
    MOCK_METHOD0(getSymbolicOperator,const std::shared_ptr<ISymbolicOperator>&());
};

#endif //SOLVER_IAPPLICATIONSTORAGEMOCK_HPP
