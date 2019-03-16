//
// Created by maciek on 13.03.19.
//


#include <gtest/gtest.h>
#include <ObjectiveFunction.hpp>

class ObjectiveFunctionTests : public ::testing::Test
{
public:
    ObjectiveFunctionTests()
    {
        const std::function<float(SVector&)> func =
            [](SVector& point){
                return (point.x(1) * point.x(1)) - (2 * point.x(1) * point.x(2)) + (point.x(2) * point.x(2));
            };
        _sut = std::make_unique<ObjectiveFunction>(2, func);
    }

    std::unique_ptr<ObjectiveFunction> _sut;
};

TEST_F(ObjectiveFunctionTests, ShouldReturnCorrectValuesForXVector)
{
    SVector vector({1, 2});
    auto returnedValue = (*_sut)(vector);
    float expectedValue = 1.f;
    ASSERT_EQ(returnedValue, expectedValue);
}