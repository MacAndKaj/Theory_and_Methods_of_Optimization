//
// Created by maciek on 07.03.19.
//

#include <algorithm>
#include <gtest/gtest.h>
#include <SVector.hpp>


class SVectorTests : public ::testing::Test
{
public:
    SVectorTests()
    {
        _sut = std::make_unique<SVector>();
    }

    void startService(std::vector<float> &vector)
    {
        _sut->setVector(vector);
    }

    std::unique_ptr<SVector> _sut;
};

TEST_F(SVectorTests, ShouldCorrectlyAddTwoVectors)
{
    std::vector<float> first, second;
    for (int i = 0; i < 10; ++i)
    {
        first.emplace_back(static_cast<float>(i));
        second.emplace_back(static_cast<float>(2 * i));
    }
    startService(first);
    SVector rhs(second);
    auto wynik = (*_sut) + rhs;
    float check = 0;
    for (const auto& item : wynik.getVector())
    {
        ASSERT_EQ(item, check + (2 * check));
        check += 1;
    }
}

TEST_F(SVectorTests, ShouldCorrectlyMultiplyVector)
{
    std::vector<float> first;
    for (int i = -5; i < 5; ++i)
    {
        first.emplace_back(static_cast<float>(i));
    }
    startService(first);


    float multiplier = 2;
    auto wynik = (*_sut)*multiplier;
    float check = -5;
    for (const auto& item : wynik.getVector())
    {
        ASSERT_EQ(item, check*multiplier);
        check += 1;
    }
}

TEST_F(SVectorTests, ShouldCorrectlySubstractTwoVectors)
{
    unsigned long numberOfElements = 121;
    std::vector<float> first(numberOfElements, 1.f), second;
    startService(first);
    for (int i = 0; i < 10; ++i)
    {
        second.emplace_back(static_cast<float>(i));
    }
    SVector rhs(second);
    auto wynik = rhs - (*_sut);
    float check = 0;
    for (const auto& item : wynik.getVector())
    {
        ASSERT_EQ(item, check - 1);
        check += 1;
    }
}

TEST_F(SVectorTests,ShouldComputeCartesianCorrectlyNorm)
{
    unsigned long numberOfElements = 121;
    std::vector<float> vector(numberOfElements, 1.f);
    startService(vector);

    float expectedNorm = 11.f;
    auto norm = _sut->getCartesianNorm();
    ASSERT_EQ(expectedNorm,norm);
}


TEST_F(SVectorTests,ShouldComputeCartesianCorrectlyNormForNegativeElements)
{
    unsigned long numberOfElements = 121;
    std::vector<float> vector(numberOfElements, -1.f);
    startService(vector);

    float expectedNorm = 11.f;
    auto norm = _sut->getCartesianNorm();
    ASSERT_EQ(expectedNorm,norm);
}