//
// Created by maciek on 08.04.19.
//


#include <gtest/gtest.h>
#include <Functions/GradientWrapper.hpp>
#include <ApplicationStorage.hpp>
#include <Functions/IFunctionsFactory.hpp>
#include <SVector.hpp>

class GradientWrapperTests : public ::testing::Test
{
public:
    GradientWrapperTests()
    {
        applicationStorage = std::make_shared<ApplicationStorage>();
    }

    void startService(const std::shared_ptr<FunctionWrapper>& function)
    {
        sut = std::make_unique<GradientWrapper>(function, applicationStorage);
    }

    std::shared_ptr<IApplicationStorage> applicationStorage;
    std::unique_ptr<GradientWrapper> sut;
};

TEST_F(GradientWrapperTests, ShouldBeCreatedWithTheDimensionOfFunction)
{
    std::string str_fun = "x1 + x1*x2 + sin(x3)";
    unsigned int dimension = 3;
    auto function =
        applicationStorage->getFunctionsFactory()->getFunctionFromString(str_fun, dimension);

    startService(function);
    ASSERT_EQ(sut->getDimension(), dimension);
}

TEST_F(GradientWrapperTests, ShouldCreateGradientThatReturnsCorrectValues)
{
    std::string str_fun = "x1 + x1*x2 + sin(x3)";
    unsigned int dimension = 3;
    auto function =
        applicationStorage->getFunctionsFactory()->getFunctionFromString(str_fun, dimension);

    startService(function);
    SVector point({1.f,1.f,M_PI});
    ASSERT_EQ(*(sut->getGradientInPoint(point)), SVector({2.f,1.f, -1.f}));
}