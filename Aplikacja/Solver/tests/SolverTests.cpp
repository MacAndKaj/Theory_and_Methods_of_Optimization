//
// Created by maciek on 01.04.19.
//

#include <gtest/gtest.h>
#include <Solver.hpp>
#include "mocks/IMethodMock.hpp"
#include <ApplicationStorage.hpp>

std::string FUNCTION = "x1+5*x2+sin(x3)+exp(x4)";

class SolverTests : public ::testing::Test
{
public:
    SolverTests()
        : _applicationStorage(new ApplicationStorage)
    {
        _sut = std::make_unique<Solver>(_applicationStorage);
    }

    std::shared_ptr<IApplicationStorage> _applicationStorage;
    std::unique_ptr<ISolver> _sut;
};

TEST_F(SolverTests, ShouldDoNothingIfMethodNotSet)
{
    _sut->setFunction(4, FUNCTION);
}