//
// Created by maciek on 06.03.19.
//

#ifndef SOLVER__VECTOR_HPP
#define SOLVER__VECTOR_HPP

#include <vector>
#include <string>
#include <Logger/Logger.hpp>

class SVector
{
public:
    SVector();
    SVector(const SVector&);
    explicit SVector(const std::vector<float>& vector);


    const std::vector<float>& getVector() const;
    void setVector(const std::vector<float>& vector);

    float x(unsigned int&&) const;
    unsigned long getSize() const;
    float getCartesianNorm() const;

    std::string toString() const;

    SVector& transpose();
    bool containsOnlyZeros()const;
    bool operator==(const SVector&)const;
    SVector& operator = (const SVector&);
    const SVector& operator -();
private:
    std::vector<float> _vector;
    Logger& _log;
    bool _colummnVector;


    friend SVector operator *(const SVector&, float);
    friend SVector operator *(const SVector&, int);
    friend std::optional<float> operator *(const SVector&, const SVector&);
    friend SVector operator +(const SVector&, const SVector&);
    friend SVector operator -(const SVector&, const SVector&);

};

std::optional<float> operator *(const SVector&, const SVector&);
SVector operator *(const SVector&, float);
SVector operator *(const SVector&, int);
SVector operator +(const SVector&, const SVector&);
SVector operator -(const SVector&, const SVector&);

#endif //SOLVERTESTS_VECTOR_HPP
