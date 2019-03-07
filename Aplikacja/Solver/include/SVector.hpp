//
// Created by maciek on 06.03.19.
//

#ifndef SOLVER__VECTOR_HPP
#define SOLVER__VECTOR_HPP

#include <vector>

class Vector
{
public:
    Vector() = default;
    explicit Vector(const std::vector<float>& vector);
    const std::vector<float>& getVector() const;
    void setVector(const std::vector<float>& vector);
private:
    std::vector<float> _vector;

    friend Vector operator +(const Vector&, const Vector&);
};

Vector operator+(const Vector& lhs, const Vector& rhs)
{
    std::vector<float> vector;
    if(not (lhs._vector.empty() and rhs._vector.empty())
        and lhs._vector.size() == rhs._vector.size())
    {
        const auto& rhsItem = rhs._vector.begin();
        for (const auto& lhsItem : lhs._vector)
        {
            vector.emplace_back(lhsItem+(*rhsItem));
        }
    }
    return Vector(vector);
}

#endif //SOLVERTESTS_VECTOR_HPP
