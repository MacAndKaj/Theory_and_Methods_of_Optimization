//
// Created by maciek on 20.03.19.
//

#include <gtest/gtest.h>
#include <SymbolicOperations/SymbolicOperator.hpp>
#include <fstream>
#include <Functions/FunctionsFactory.hpp>
#include <ApplicationStorage.hpp>

class SymbolicOperatorTests : public ::testing::Test
{
public:
    SymbolicOperatorTests()
    {
        _applicationStorage= std::make_shared<ApplicationStorage>();
        _sut = SymbolicOperator::getInstance(_applicationStorage);
    }

    std::shared_ptr<IApplicationStorage> _applicationStorage;
    std::shared_ptr<ISymbolicOperator> _sut;
};

TEST_F(SymbolicOperatorTests, ShouldPass)
{
    std::string exampleFunction("x1 + 2*x2 + sin(x3) + 100");
//
//    auto function = _functionGetter->parseStringToSFunction(exampleFunction, 3);
//
//    auto ret = _sut->getDerivatives(function);
//    ASSERT_EQ(ret.size(),3);
}