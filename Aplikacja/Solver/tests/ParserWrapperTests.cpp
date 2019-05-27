//
// Created by maciek on 19.03.19.
//

#include <gtest/gtest.h>
#include <Functions/ParserWrapper.hpp>
#include <SVector.hpp>
#include <cmath>

class ParserWrapperTests : public ::testing::Test, public ParserWrapper
{
public:
    ParserWrapperTests()
    {

    }
};


TEST_F(ParserWrapperTests, ShouldCreateFunctionThatReturnsCorrectResult)
{
    std::string exampleFunction("x1 + 2*x2");
    SVector point({1, 1});

    auto function = parseToFunction(2, exampleFunction);
    auto result = (*function)(point);
    ASSERT_TRUE(result);
}

TEST_F(ParserWrapperTests, ShouldReturnEmptyOptionalIfDimensionsAreNotSame)
{
    std::string exampleFunction("x1 + 2*x2");
    SVector point({1, 1, 1, 1});

    auto function = parseToFunction(3, exampleFunction);
    auto result = (*function)(point);
    ASSERT_FALSE(result);
}

TEST_F(ParserWrapperTests, ShouldComputeCorrectValueForSpecializedFunction)
{
    std::string exampleFunction("x1 + 2*x2 + sin(x3) + 100");
    SVector point({5, 1,M_PI/2});

    auto function = parseToFunction(3, exampleFunction);
    auto result = (*function)(point);
    ASSERT_EQ(*result, 108);
}

TEST_F(ParserWrapperTests,ShouldReturnCorrectDimensionVector)
{
    std::string exampleFunction("x1*x2 + sin(x3) + exp(x4) + x5^3");
    unsigned int dimension=5;
    auto function = parseToFunction(dimension, exampleFunction);

    ASSERT_EQ(function->getDimension(),dimension);
}
