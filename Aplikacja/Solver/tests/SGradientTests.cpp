//
// Created by maciek on 17.03.19.
//


#include <gtest/gtest.h>
#include <Functions/SGradient.hpp>
#include <SVector.hpp>

class SGradientTests : public ::testing::Test
{
public:
    SGradientTests()
    {
        std::vector<std::function<float(SVector&)>> gradient = {
            [](SVector& point){ return point.x(1);},
            [](SVector& point){ return point.x(2);},
            [](SVector& point){ return point.x(3);},
        };

        _sut = std::make_unique<SGradient>(gradient);
    }

    std::unique_ptr<SGradient> _sut;
};

TEST_F(SGradientTests, ShouldReturnCorrectGradient)
{
    SVector vector({1,1,1});
    SVector expectedResult({1,2,3});

    auto result = (*_sut)(vector);
    ASSERT_TRUE(result.get() == expectedResult);
}