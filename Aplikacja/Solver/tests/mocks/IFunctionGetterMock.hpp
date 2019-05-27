//
// Created by maciek on 01.04.19.
//

#ifndef SOLVER_IPARSERWRAPPERMOCK_HPP
#define SOLVER_IPARSERWRAPPERMOCK_HPP

#include <gmock/gmock.h>
#include <Functions/IFunctionsFactory.hpp>



class IFunctionGetterMock : public IFunctionGetter
{
public:
    MOCK_METHOD2(parseStringToSFunction, std::shared_ptr<FunctionWrapper>(
        const std::string&, unsigned int));
};

#endif //SOLVER_IPARSERWRAPPERMOCK_HPP
