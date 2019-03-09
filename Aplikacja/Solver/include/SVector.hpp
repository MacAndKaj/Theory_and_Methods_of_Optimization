//
// Created by maciek on 06.03.19.
//

#ifndef SOLVER__VECTOR_HPP
#define SOLVER__VECTOR_HPP

#include <vector>

class SVector
{
public:
    SVector() = default;
    explicit SVector(const std::vector<float>& vector);

    const std::vector<float>& getVector() const;
    void setVector(const std::vector<float>& vector);

    float cartesianNorm()const;

private:
    std::vector<float> _vector;

    friend SVector operator *(const SVector&, float);
    friend SVector operator +(const SVector&, const SVector&);
    friend SVector operator -(const SVector&, const SVector&);

};

SVector operator *(const SVector&, float);
SVector operator +(const SVector&, const SVector&);
SVector operator -(const SVector&, const SVector&);

#endif //SOLVERTESTS_VECTOR_HPP
