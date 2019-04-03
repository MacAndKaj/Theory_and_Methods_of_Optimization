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
        _sut = std::make_unique<SMatrix>();
    }

    std::unique_ptr<SMatrix> _sut;
};

