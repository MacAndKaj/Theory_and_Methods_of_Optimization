//
// Created by maciek on 06.03.19.
//

#include <Vector.hpp>

#include "Vector.hpp"

Vector::Vector(const std::vector<float>& vector)
    : _vector(vector)
{

}

const std::vector<float>& Vector::getVector() const
{
    return _vector;
}

void Vector::setVector(const std::vector<float>& vector)
{
    _vector = vector;
}
