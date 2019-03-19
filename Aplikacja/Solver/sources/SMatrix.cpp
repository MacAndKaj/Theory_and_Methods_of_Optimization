//
// Created by maciek on 06.03.19.
//

#include <SMatrix.hpp>
#include <Logger/LoggersFactory.hpp>

SMatrix::SMatrix()
    : _log(LoggersFactory::getLoggersFactory().getLogger("SMatrix"))
{

}

SMatrix::SMatrix(const std::vector<std::vector<float>>& vector)
    : _vector(vector)
    , _log(LoggersFactory::getLoggersFactory().getLogger("SMatrix"))
{
    if (not vector.empty())
    {
        _dimension = {vector.begin()->size(), vector.size()};
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
    if(not (_dimension.first == 0 and _dimension.second == 0))
    {
        for (int i = 0; i < _vector.size(); ++i)
        {
            for (int j = 0; j < _vector[0].size(); ++j)
            {
                if (_vector[i][j] != other._vector[i][j]) return false;
            }
        }
    }
    return true;
}

std::optional<float> SMatrix::getMinor(unsigned int&) const
{
//    if()
    return std::optional<float>();
}
