//
// Created by maciek on 06.03.19.
//
#include <PolakRibiereMethod.hpp>
#include "Solver.hpp"

Solver::Solver()
    : _methodType(MethodType::MethodType_Unknown)
{

}

void Solver::setMethod(MethodType methodType)
{
    _methodType = methodType;
}

void Solver::computeSolution() const
{

}

SSolution Solver::getSolution() const
{
    return SSolution();
}

