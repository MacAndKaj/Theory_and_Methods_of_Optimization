//
// Created by maciek on 20.03.19.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <SymbolicOperations/SymbolicOperator.hpp>
#include <fstream>
#include <Functions/FunctionsFactory.hpp>
#include <mocks/IApplicationStorageMock.hpp>

using namespace ::testing;

class SymbolicOperatorTests : public Test
{
public:
    SymbolicOperatorTests()
        : _applicationStorageMock(new IApplicationStorageMock())
    {
        _functionsFactory = FunctionsFactory::getInstance(_applicationStorageMock);
        EXPECT_CALL(*_applicationStorageMock, getFunctionsFactory)
            .WillRepeatedly(ReturnRef(_functionsFactory));
        _sut = SymbolicOperator::getInstance(_applicationStorageMock);
    }

    std::shared_ptr<IFunctionsFactory> _functionsFactory;
    std::shared_ptr<IApplicationStorageMock> _applicationStorageMock;
    std::shared_ptr<ISymbolicOperator> _sut;
};

TEST_F(SymbolicOperatorTests, ShouldReturnFunctionInCorrectDimension)
{
    std::string exampleFunction("x1 + 2*x2 + sin(x3) + 100");

    auto function = _functionsFactory->getFunctionFromString(exampleFunction, 3);

    auto ret = _sut->getDerivatives(function);
    ASSERT_EQ(ret.size(), 3);
}

TEST_F(SymbolicOperatorTests, Print)
{
    std::string exampleFunction("x1 + x1*x2 + sin(x3) + exp(x4) + (x5)**3");
    unsigned int dimension = 5;
    auto function = _functionsFactory->getFunctionFromString(exampleFunction, dimension);
    auto ret = _sut->getDerivatives(function);

    ASSERT_EQ(ret.size(),dimension);
}
