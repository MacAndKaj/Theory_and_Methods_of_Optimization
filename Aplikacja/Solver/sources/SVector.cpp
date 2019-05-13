//
// Created by maciek on 06.03.19.
//

#include <cmath>
#include <algorithm>
#include <SVector.hpp>
#include <Logger/LoggersFactory.hpp>
#include <sstream>
#include <iomanip>

SVector::SVector()
    : _log(LoggersFactory::getLoggersFactory().getLogger("SVector"))
    , _colummnVector(true)
{

}

SVector::SVector(const SVector& arg)
    : _log(LoggersFactory::getLoggersFactory().getLogger("SVector"))
    , _colummnVector(true)
{
    for (const auto& item : arg._vector)
    {
        _vector.push_back(item);
    }
}

SVector::SVector(const std::vector<double>& vector)
    : _vector(vector)
    , _log(LoggersFactory::getLoggersFactory().getLogger("SVector"))
    , _colummnVector(true)
{

}

const std::vector<double>& SVector::getVector() const
{
    return _vector;
}

void SVector::setVector(const std::vector<double>& vector)
{
    _vector = vector;
}

double SVector::getCartesianNorm() const
{
    double sum = 0;
    for (const auto& item : _vector)
    {
        sum += (item * item);
    }

    return std::sqrt(sum);
}

SVector& SVector::transpose()
{
    _colummnVector = false;
    return *this;
}

unsigned long SVector::getSize() const
{
    return _vector.size();
}

/// Returns x_i from vector x = [x_1 x_2 ... x_n]
/// \param index from range 1...n
/// \return x - double
double SVector::x(unsigned int&& index) const
{
    if (_vector.size() < index)
    {
        _log << "EIndex is out of range for vector!";
        return 0;
    }
    return _vector[index - 1];
}

bool SVector::containsOnlyZeros() const
{
    return _vector.cend() == std::find_if(_vector.cbegin(), _vector.cend(), [](const double& elem){
        return elem != 0;
    });
}

const SVector& SVector::operator -()
{
    std::for_each(_vector.begin(), _vector.end(), [](double& element){
        element *= (-1);
    });
    return *this;
}

bool SVector::operator ==(const SVector& arg) const
{
    if (arg.getSize() != getSize())return false;
    for (int i = 0; i < getSize(); ++i)
    {
        if (std::fabs(_vector[i] - arg._vector[i]) > std::numeric_limits<double>::epsilon())
        {
            return false;
        }
    }
    return true;
}

std::string SVector::toString() const
{
    std::stringstream strm;
    strm << "[";
    for (const auto& item : _vector)
    {

        strm<<" ";
        strm << item << std::setprecision(5);
    }
    strm << " ]";
    return strm.str();
}


//===================== friends ========================================

SVector operator *(const SVector& lhs, int a)
{
    std::vector<double> tempVector;
    for (auto&& item : lhs._vector)
    {
        tempVector.emplace_back(item*a);
    }

    return SVector(tempVector);
}

SVector operator *(const SVector& lhs, double a)
{
    std::vector<double> tempVector;
    for (auto&& item : lhs._vector)
    {
        tempVector.emplace_back(item * a);
    }

    return SVector(tempVector);
}


/// Doesn't support multitplying column vector by row vector.
/// \param lhs row vector
/// \param rhs column vector
/// \return double - product of multilying row vector by column one
std::optional<double> operator *(const SVector& lhs, const SVector& rhs)
{
    if (lhs._colummnVector or not rhs._colummnVector) return {};
    auto sum = 0.f;
    for (int i = 0; i < lhs._vector.size(); ++i)
    {
        sum += (lhs._vector[i] * rhs._vector[i]);
    }
    return sum;
}

SVector operator -(const SVector& lhs, const SVector& rhs)
{
    return lhs + (rhs * (-1));
}

SVector operator +(const SVector& lhs, const SVector& rhs)
{
    std::vector<double> vector;
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

SVector& SVector::operator =(const SVector& other)
{
    _vector = other._vector;
    _colummnVector = other._colummnVector;
    return *this;
}

SVector operator *(double a, const SVector& sVector)
{
    return sVector*a;
}

SVector operator *(int a, const SVector& sVector)
{
    return sVector*a;
}


//---------------------------------------------------------------------------------------------
