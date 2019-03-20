//
// Created by maciek on 19.03.19.
//

#include <gtest/gtest.h>
#include <FunctionGetter/ParserWrapper.hpp>
#include <SVector.hpp>
#include <cmath>

class ParserWrapperTests : public ::testing::Test
{
public:
    ParserWrapperTests()
        : toRemove(1111)
    {
        _sut = std::make_unique<ParserWrapper>();
    }

    unsigned int toRemove;
    std::unique_ptr<ParserWrapper> _sut;
};


TEST_F(ParserWrapperTests, ShouldCreateFunctionThatReturnsCorrectResult)
{
    std::string exampleFunction("x1 + 2*x2");
    SVector point({1, 1});

    auto function = _sut->parseToFunction(2, exampleFunction);
    auto result = (*function)(point);
    ASSERT_TRUE(result);
}

TEST_F(ParserWrapperTests, ShouldReturnEmptyOptionalIfDimensionsAreNotSame)
{
    std::string exampleFunction("x1 + 2*x2");
    SVector point({1, 1, 1, 1});

    auto function = _sut->parseToFunction(3, exampleFunction);
    auto result = (*function)(point);
    ASSERT_FALSE(result);
}

TEST_F(ParserWrapperTests, ShouldComputeCorrectValueForSpecializedFunction)
{
    std::string exampleFunction("x1 + 2*x2 + 1000");
    SVector point({5, 1});

    auto function = _sut->parseToFunction(2, exampleFunction);
    auto result = (*function)(point);
    ASSERT_EQ(*result, 1007);
}
