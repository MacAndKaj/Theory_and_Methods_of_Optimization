//
// Created by maciek on 06.03.19.
//

#include <SVector.hpp>
#include <iostream>
#include <cmath>
#include <Logger/LoggersFactory.hpp>

SVector::SVector()
    : _log(LoggersFactory::getLoggersFactory().getLogger("SVector"))
{

}

SVector::SVector(const SVector& arg)
    : _log(LoggersFactory::getLoggersFactory().getLogger("SVector"))
{
    for (const auto& item : arg._vector)
    {
        _vector.push_back(item);
    }
}

SVector::SVector(const std::vector<float>& vector)
    : _vector(vector)
    , _log(LoggersFactory::getLoggersFactory().getLogger("SVector"))
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

SVector operator *(const SVector& lhs, float a)
{
    std::vector<float> tempVector;
    for (auto&& item : lhs._vector)
    {
        tempVector.emplace_back(item * a);
    }

    return SVector(tempVector);
}

SVector operator +(const SVector& lhs, const SVector& rhs)
{
    std::vector<float> vector;
    if (not(lhs._vector.empty() and rhs._vector.empty())
        and lhs._vector.size() == rhs._vector.size())
    {
        auto rhsItem = rhs._vector.cbegin();
        for (const auto& lhsItem : lhs._vector)
        {
            vector.emplace_back(lhsItem + (*rhsItem));
            rhsItem++;
        }
    }
    return SVector(vector);
}

SVector operator -(const SVector& lhs, const SVector& rhs)
{
    return lhs + (rhs * (-1));
}

float SVector::getCartesianNorm() const
{
    float sum = 0;
    for (const auto& item : _vector)
    {
        sum += (item * item);
    }

    return std::sqrt(sum);
}

unsigned long SVector::getSize() const
{
    return _vector.size();
}

/// Returns x_i from vector x = [x_1 x_2 ... x_n]
/// \param index from range 1...n
/// \return x - float
float SVector::x(unsigned int&& index) const
{
    if (_vector.size() < index)
    {
        _log << "Index is out of range for vector!";
        return 0;
    }
    return _vector[index - 1];
}

std::string SVector::toString() const
{
    std::string result("[");
    for (const auto& item : _vector)
    {
        result.append(" ");
        result.append(std::to_string(item));
    }
    result.append(" ]");
    return result;
}

bool SVector::operator ==(const SVector& arg) const
{
    if (arg.getSize() != getSize())return false;
    for (int i = 0; i < getSize(); ++i)
    {
        if (_vector[i] != arg._vector[i]) return false;
    }
    return true;
}



//---------------------------------------------------------------------------------------------