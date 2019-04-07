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
        std::vector<std::vector<float>> matrix = {{  1, 2, 3}
                                                  , {9, 2, 9}
                                                  , {5, 2, 0}};
        _sut = std::make_unique<SMatrix>(matrix);
    }

    std::unique_ptr<SMatrix> _sut;
};


TEST_F(SMatrixTests, ShouldFindOutDifferenceBetweenMatrices)
{
    std::vector<std::vector<float>> matrix = {{  1, 2, 3}
                                              , {9, 2, 9}
                                              , {5, 2, 1}};
    SMatrix comparingMatrix(matrix);
    ASSERT_NE(*_sut,comparingMatrix);
}


TEST_F(SMatrixTests, OperationOfDifferencingShouldReturnCorrectResult)
{

    std::vector<std::vector<float>> substrat = {{  0, 2, 3}
                                              , {9, 1, 9}
                                              , {5, 2, -1}};
    std::vector<std::vector<float>> product = {{  1, 0, 0}
                                              , {0, 1, 0}
                                              , {0, 0, 1}};
    SMatrix substractMatrix(substrat), productMatrix(product);
    auto mat = *_sut-substractMatrix;

    ASSERT_EQ(mat,productMatrix);
}


TEST_F(SMatrixTests, ShouldCorrectlyMultpiplyMatrices)
{
    std::vector<std::vector<float>> substrat = {{  1, 0, 0}
                                               , {0, 1, 0}
                                               , {0, 0, 1}};
    SMatrix multiplier(substrat);
    auto mat = (*_sut) * multiplier;
    ASSERT_EQ(mat,(*_sut));
}