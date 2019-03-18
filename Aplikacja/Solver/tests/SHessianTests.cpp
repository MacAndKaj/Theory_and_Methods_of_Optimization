//
// Created by maciek on 18.03.19.
//


#include <gtest/gtest.h>
#include <Functions/SHessian.hpp>
#include <SMatrix.hpp>

class SHessianTests : public ::testing::Test
{
    using HessianForm = std::vector<std::vector<std::function<float(SVector&)>>>;
public:
    SHessianTests()
        : _dimension({3, 3})
    {
        HessianForm hessian = {
            {
                [](SVector& point){ return 1 * point.x(1); }, [](SVector& point){
                return 2 * point.x(2);
            }    , [](SVector& point){ return 3 * point.x(3); },}
            , {
                [](SVector& point){ return 1 * point.x(1); }, [](SVector& point){
                    return 2 * point.x(2);
                }, [](SVector& point){ return 3 * point.x(3); }
            }
            , {
                [](SVector& point){ return 1 * point.x(1); }, [](SVector& point){
                    return 2 * point.x(2);
                }, [](SVector& point){ return 3 * point.x(3); }
            }
            ,};

        _sut = std::make_unique<SHessian>(hessian);
    }

    std::pair<unsigned, unsigned> _dimension;
    std::unique_ptr<SHessian> _sut;
};

TEST_F(SHessianTests, ShouldReturnCorrectDimension)
{
    ASSERT_EQ(_sut->getDimension().first, _dimension.first);
    ASSERT_EQ(_sut->getDimension().second, _dimension.second);
}

TEST_F(SHessianTests, ShouldCorrectlyComputeHessianInPoint)
{
    SVector point({1, 1, 1});
    SMatrix expectedResult({{  1, 2, 3}
                            , {1, 2, 3}
                            , {1, 2, 3}});

    auto result = (*_sut)(point);
    ASSERT_EQ(*result,expectedResult);
}