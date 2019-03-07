#include <cmath>

//
// Created by maciek on 06.03.19.
//

#include <SVector.hpp>
#include <iostream>
#include <cmath>
#include "SVector.hpp"

SVector::SVector(const std::vector<float>& vector)
    : _vector(vector)
{

}

const std::vector<float>& SVector::getVector() const
{
    return _vector;
}

void SVector::setVector(const std::vector<float>& vector)
{
    _vector = vector;
}

//------------------------------- NON MEMBER OPERATORS --------------------------------------------


SVector operator *(const SVector& lhs,float a)
{
    std::vector<float> tempVector;
    for (auto&& item : lhs._vector)
    {
        tempVector.emplace_back(item * a);
    }

    return SVector(tempVector);
}


SVector operator+(const SVector& lhs, const SVector& rhs)
{
    std::vector<float> vector;
    if(not (lhs._vector.empty() and rhs._vector.empty())
       and lhs._vector.size() == rhs._vector.size())
    {
        auto rhsItem = rhs._vector.cbegin();
        for (const auto& lhsItem : lhs._vector)
        {
            vector.emplace_back(lhsItem+(*rhsItem));
            rhsItem++;
        }
    }
    return SVector(vector);
}

SVector operator -(const SVector& lhs, const SVector& rhs)
{
    return lhs + (rhs*(-1));
}

float SVector::cartesianNorm() const
{
    float sum=0;
    for (const auto& item : _vector)
    {
        sum += (item*item);
    }

    return std::sqrt(sum);
}



//---------------------------------------------------------------------------------------------