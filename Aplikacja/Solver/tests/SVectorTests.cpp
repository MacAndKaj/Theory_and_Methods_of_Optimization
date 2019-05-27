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

    void startService(std::vector<double> &vector)
    {
        _sut->setVector(vector);
    }

    std::unique_ptr<SVector> _sut;
};

TEST_F(SVectorTests, ShouldCorrectlyAddTwoVectors)
{
    std::vector<double> first, second;
    for (int i = 0; i < 10; ++i)
    {
        first.emplace_back(static_cast<double>(i));
        second.emplace_back(static_cast<double>(2 * i));
    }
    startService(first);
    SVector rhs(second);
    auto wynik = (*_sut) + rhs;
    double check = 0;
    for (const auto& item : wynik.getVector())
    {
        ASSERT_EQ(item, check + (2 * check));
        check += 1;
    }
}

TEST_F(SVectorTests, ShouldCorrectlyMultiplyVector)
{
    std::vector<double> first;
    for (int i = -5; i < 5; ++i)
    {
        first.emplace_back(static_cast<double>(i));
    }
    startService(first);


    double multiplier = 2;
    auto wynik = (*_sut)*multiplier;
    double check = -5;
    for (const auto& item : wynik.getVector())
    {
        ASSERT_EQ(item, check*multiplier);
        check += 1;
    }
}

TEST_F(SVectorTests, ShouldCorrectlySubstractTwoVectors)
{
    unsigned long numberOfElements = 121;
    std::vector<double> first(numberOfElements, 1.f), second;
    startService(first);
    for (int i = 0; i < 10; ++i)
    {
        second.emplace_back(static_cast<double>(i));
    }
    SVector rhs(second);
    auto wynik = rhs - (*_sut);
    double check = 0;
    for (const auto& item : wynik.getVector())
    {
        ASSERT_EQ(item, check - 1);
        check += 1;
    }
}

TEST_F(SVectorTests,ShouldComputeCartesianCorrectlyNorm)
{
    unsigned long numberOfElements = 121;
    std::vector<double> vector(numberOfElements, 1.f);
    startService(vector);

    double expectedNorm = 11.f;
    auto norm = _sut->getCartesianNorm();
    ASSERT_EQ(expectedNorm,norm);
}


TEST_F(SVectorTests,ShouldComputeCartesianCorrectlyNormForNegativeElements)
{
    unsigned long numberOfElements = 121;
    std::vector<double> vector(numberOfElements, -1.f);
    startService(vector);

    double expectedNorm = 11.f;
    auto norm = _sut->getCartesianNorm();
    ASSERT_EQ(expectedNorm,norm);
}

TEST_F(SVectorTests, ShouldCorrectlyCheckIfVectorContainsOnlyZeros)
{
    unsigned long numberOfElements = 121;
    std::vector<double> vec(numberOfElements, 0);
    startService(vec);
    auto containsOnlyZeros = _sut->containsOnlyZeros();
    ASSERT_TRUE(containsOnlyZeros);
}

TEST_F(SVectorTests, ShouldCorrectlyCheckIfVectorContainsNotOnlyZeros)
{
    unsigned long numberOfElements = 121;
    std::vector<double> vec(numberOfElements, 0);
    vec[numberOfElements-1] = 1;
    startService(vec);
    auto containsOnlyZeros = _sut->containsOnlyZeros();
    ASSERT_FALSE(containsOnlyZeros);

    vec[numberOfElements-1] = 0;
    vec[0] = 1;
    _sut->setVector(vec);
    ASSERT_FALSE(containsOnlyZeros);
}

TEST_F(SVectorTests, ShouldReturnNegativeVector)
{
    std::vector<double> vec{-1.f,-5.2,2.f,0,111.21,-123.f};
    startService(vec);
    auto negative = -(*_sut);

    for (int i = 0; i < negative.getSize(); ++i)
    {
        ASSERT_EQ(-vec[i],negative.x(i+1));
    }
}
