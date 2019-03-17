//
// Created by maciek on 13.03.19.
//

#include <gtest/gtest.h>
#include <Functions/SFunction.hpp>
#include <SVector.hpp>
#include <Definitions_and_Helpers/Optional.hpp>

class SFunctionTests : public ::testing::Test
{
public:
    SFunctionTests()
        : _dimension(2)
    {
        //f(x) = (x_1)^2 - 2*x_1*x_2 + (x_2)^2
        std::function<float(SVector&)> func =
            [](SVector& point){
                return (point.x(1) * point.x(1)) - (2 * point.x(1) * point.x(2)) + (point.x(2) * point.x(2));
            };

        _sut = std::make_unique<SFunction>(_dimension, func);
    }

    unsigned int _dimension;
    std::unique_ptr<SFunction> _sut{};
};

TEST_F(SFunctionTests, ShouldReturnCorrectDimenstion)
{
    auto dimension = _sut->getDimension();
    auto expectedDimension = 2;
    ASSERT_EQ(dimension, expectedDimension);

}

TEST_F(SFunctionTests, ShouldReturnCorrectValuesForXVector)
{
    SVector vector({1, 2});
    auto returnedValue = (*_sut)(vector);
    auto expectedValue = 1.f;
    ASSERT_EQ(returnedValue.get(), expectedValue);
}

