//
// Created by maciek on 18.03.19.
//


#include <gtest/gtest.h>
#include <SMatrix.hpp>

class SMatrixTests : public ::testing::Test
{
public:
    SMatrixTests()
    {
        std::vector<std::vector<double>> matrix = {{  1, 2, 3}
                                                   , {9, 2, 9}
                                                   , {5, 2, 0}};
        _sut = std::make_unique<SMatrix>(matrix);
    }

    std::unique_ptr<SMatrix> _sut;
};

TEST_F(SMatrixTests, ShouldFindOutDifferenceBetweenMatrices)
{
    std::vector<std::vector<double>> matrix = {{  1, 2, 3}
                                               , {9, 2, 9}
                                               , {5, 2, 1}};
    SMatrix comparingMatrix(matrix);
    ASSERT_NE(*_sut, comparingMatrix);
}

TEST_F(SMatrixTests, OperationOfDifferencingShouldReturnCorrectResult)
{

    std::vector<std::vector<double>> substrat = {{  0, 2, 3}
                                                 , {9, 1, 9}
                                                 , {5, 2, -1}};
    std::vector<std::vector<double>> product = {{  1, 0, 0}
                                                , {0, 1, 0}
                                                , {0, 0, 1}};
    SMatrix substractMatrix(substrat), productMatrix(product);
    auto mat = *_sut - substractMatrix;

    ASSERT_EQ(mat, productMatrix);
}

TEST_F(SMatrixTests, ShouldCorrectlyMultpiplyMatrices)
{
    std::vector<std::vector<double>> substrat = {{  1, 0, 0}
                                                 , {0, 1, 0}
                                                 , {0, 0, 1}};
    SMatrix multiplier(substrat);
    auto mat = (*_sut) * multiplier;
    ASSERT_EQ(mat, (*_sut));
}

TEST_F(SMatrixTests, ShouldCorrectlyComputeDeterminant)
{
    double det = 96.;
    ASSERT_DOUBLE_EQ(*_sut->det(),det);
}

TEST_F(SMatrixTests, ShouldCorrectlyComputeMainSubdeterminants)
{
    std::vector<double> expectedSubdeterminants = {1., -16., 96.};
    auto subdeterminants = _sut->getSubDeterminants();
    auto iter = subdeterminants.begin();
    for (const auto & det : expectedSubdeterminants)
    {
        ASSERT_DOUBLE_EQ(det,(*iter++));
    }
}

