//
// Created by maciek on 01.04.19.
//

#ifndef SOLVER_IMETHODMOCK_HPP
#define SOLVER_IMETHODMOCK_HPP

#include <gmock/gmock.h>
#include <Methods/IMethod.hpp>


class IMethodMock : public IMethod
{
public:
    MOCK_METHOD0(startComputing, bool());
    MOCK_METHOD1(setFunction, void(const std::shared_ptr<FunctionWrapper>&));
    MOCK_CONST_METHOD0(getSolution, SSolution());
};

#endif //SOLVER_IMETHODMOCK_HPP
