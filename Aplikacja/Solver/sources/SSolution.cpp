#include <utility>

//
// Created by maciek on 07.03.19.
//

#include <SSolution.hpp>
#include <iostream>

SSolution::SSolution(std::vector<SVector>  points,const double value)
    : _points(std::move(points))
{
    _values.push_back(value);
}

void SSolution::addNewPoint(const SVector& point, double value)
{
    _points.push_back(point);
    _values.push_back(value);
}

SVector SSolution::getLastPoint() const
{
    return *_points.rbegin();
}

SVector SSolution::getSecondLastPoint() const
{
    return *(++_points.rbegin());
}

std::vector<std::pair<SVector, double>> SSolution::getSolutionAsMap() const
{
    std::vector<std::pair<SVector, double>> returnedVector;

    auto valuesIter = _values.cbegin();
    for (const auto& point : _points)
    {
        returnedVector.emplace_back(point,*valuesIter);
        valuesIter++;
    }

    return returnedVector;
}

int SSolution::getSize() const
{
    return _points.size();
}

