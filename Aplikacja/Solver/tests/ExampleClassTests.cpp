//
// Created by maciek on 06.03.19.
//

#include <gtest/gtest.h>
#include "ExampleClass.hpp"


class ExampleClassTests : public ::testing::Test
{
public:
    ExampleClassTests()
    {
        _sut = std::make_unique<ExampleClass>();
    }

    std::unique_ptr<ExampleClass> _sut;
};

TEST_F(ExampleClassTests, ShouldReturnValueEqualToFive)
{
    unsigned int expectedValue = 5;
    ASSERT_EQ(expectedValue, _sut->getFive());
}

TEST_F(ExampleClassTests, ShouldReturnValueNotEqualToFive)
{
    unsigned int expectedValue = 5;
    ASSERT_NE(expectedValue, _sut->getFive(true));
}