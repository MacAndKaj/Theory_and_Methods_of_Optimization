//
// Created by maciek on 20.03.19.
//

#include <gtest/gtest.h>
#include <Functions/FunctionWrapper.hpp>

class FunctionWrapperTests : public ::testing::Test
{
public:
    FunctionWrapperTests()
    {
        _sut = std::make_unique<FunctionWrapper>();
    }

    exprtk::parser<float> _parser;
    std::unique_ptr<FunctionWrapper> _sut;
};



TEST_F(FunctionWrapperTests, ShouldCorrectlyDoAFunctionAndComputeInInitialState)
{
    std::string exampleFunction("x1 + 2*x2");
    std::vector<std::pair<std::string, float>> namesAndValues = {{"x1", 0}, {"x2", 0}};
    _sut->addSymbols(namesAndValues);

    auto expression = _sut->configAndGetExpression(exampleFunction);
    _parser.compile(exampleFunction, expression);
    ASSERT_EQ(expression.value(), 0);

}

TEST_F(FunctionWrapperTests, ShouldNotDoAFunction)
{
    std::string exampleFunction("x1 + 2*x2");
    std::vector<std::pair<std::string, float>> namesAndValues = {{"x1", 0}};
    _sut->addSymbols(namesAndValues);

    auto expression = _sut->configAndGetExpression(exampleFunction);
    ASSERT_FALSE(_parser.compile(exampleFunction, expression));
}