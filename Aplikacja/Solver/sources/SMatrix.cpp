//
// Created by maciek on 06.03.19.
//
#include <cmath>
#include <sstream>
#include <iostream>
#include <SMatrix.hpp>
#include <Logger/LoggersFactory.hpp>

SMatrix::SMatrix()
    : _log(LoggersFactory::getLoggersFactory().getLogger("SMatrix"))
{

}

SMatrix::SMatrix(const std::vector<std::vector<double>>& vector)
    : _vector(vector)
    , _log(LoggersFactory::getLoggersFactory().getLogger("SMatrix"))
{
    if (not vector.empty())
    {
        _dimension = {vector.size(), vector.begin()->size()};
    }
    else
    {
        _dimension = {0, 0};
    }
}

bool SMatrix::operator ==(const SMatrix& other) const
{
    if ((_dimension.first != other._dimension.first) or
        (_dimension.second != other._dimension.second))
    {
        return false;
    }
    if (not(_dimension.first == 0 and _dimension.second == 0))
    {
        for (int i = 0; i < _vector.size(); ++i)
        {
            for (int j = 0; j < _vector[0].size(); ++j)
            {
                if (std::fabs(_vector[i][j] - other._vector[i][j]) >
                    std::numeric_limits<double>::epsilon())
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool SMatrix::operator !=(const SMatrix& secondMatrix) const
{
    return not(*this == secondMatrix);
}

std::optional<double> SMatrix::getMinor(unsigned int&) const
{
//    if()
    return std::optional<double>();
}

const SMatrix& SMatrix::operator -()
{
    for (auto&& row : _vector)
    {
        for (auto&& column : row)
        {
            column *= (-1);
        }
    }

    return *this;
}

SMatrix operator *(const SMatrix& matrix, double multiplier)
{
    std::vector<std::vector<double>> matrixReturned(matrix._dimension.first);
    auto matrixRowsIter = matrixReturned.begin();
    for (auto&& row : matrix._vector)
    {
        matrixRowsIter->reserve(matrix._dimension.second);
        for (auto&& column : row)
        {
            matrixRowsIter->push_back(column * multiplier);
        }
        ++matrixRowsIter;
    }
    return SMatrix(matrixReturned);
}

SMatrix operator +(const SMatrix& lhs, const SMatrix& rhs)
{
    if ((lhs._dimension.first != rhs._dimension.first) or
        (lhs._dimension.second != rhs._dimension.second))
    {
        return SMatrix();
    }
    std::vector<std::vector<double>> matrixReturned(lhs._dimension.first);
    auto matrixRowsIter = matrixReturned.begin();
    for (int row_nr = 0; row_nr < lhs._dimension.first; ++row_nr)
    {
        matrixRowsIter->reserve(lhs._dimension.second);
        for (int col_nr = 0; col_nr < lhs._dimension.second; ++col_nr)
        {
            matrixRowsIter->push_back(
                lhs._vector[row_nr][col_nr] + rhs._vector[row_nr][col_nr]
            );
        }
        ++matrixRowsIter;
    }
    return SMatrix(matrixReturned);
}

SMatrix operator -(const SMatrix& lhs, const SMatrix& rhs)
{
    if ((lhs._dimension.first != rhs._dimension.first) or
        (lhs._dimension.second != rhs._dimension.second))
    {
        return SMatrix();
    }
    std::vector<std::vector<double>> matrixReturned(lhs._dimension.first);
    auto matrixRowsIter = matrixReturned.begin();
    for (int row_nr = 0; row_nr < lhs._dimension.first; ++row_nr)
    {
        matrixRowsIter->reserve(lhs._dimension.second);
        for (int col_nr = 0; col_nr < lhs._dimension.second; ++col_nr)
        {
            matrixRowsIter->push_back(
                lhs._vector[row_nr][col_nr] - rhs._vector[row_nr][col_nr]
            );
        }
        ++matrixRowsIter;
    }
    return SMatrix(matrixReturned);

}

const std::vector<std::vector<double>>& SMatrix::getVector() const
{
    return _vector;
}

void SMatrix::setVector(const std::vector<std::vector<double>>& vector)
{
    if (not vector.empty())
    {
        _dimension = {vector.size(), vector.begin()->size()};
    }
    else
    {
        _dimension = {0, 0};
    }
    _vector = vector;
}

SMatrix operator *(const SMatrix& lhs, const SMatrix& rhs)
{
    if (lhs._dimension.second != rhs._dimension.first) return SMatrix();

    std::vector<std::vector<double>> matrixReturned(lhs._dimension.first);
    auto matrixRowsIter = matrixReturned.begin();
    for (const auto& row : lhs._vector)
    {
        matrixRowsIter->reserve(rhs._dimension.second);
        for (const auto& column : rhs._vector)
        {
            matrixRowsIter->emplace_back(0.f);
            for (int j = 0; j < lhs._dimension.second; ++j)
            {
                (*matrixRowsIter->rbegin()) += row[j] * column[j];
            }
        }
        ++matrixRowsIter;
    }
    return SMatrix(matrixReturned);
}

std::string SMatrix::toString() const
{
    std::stringstream strm;
    for (const auto& row : _vector)
    {
        strm << "[ ";
        for (const auto& column : row)
        {
            strm << std::to_string(column) << ' ';
        }
        strm << "]\n";
    }
    return strm.str();
}
