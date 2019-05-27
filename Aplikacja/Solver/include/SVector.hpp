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
    SVector(const std::vector<double>& vector);


    const std::vector<double>& getVector() const;
    void setVector(const std::vector<double>& vector);

    double x(unsigned int&&) const;
    unsigned long getSize() const;
    double getCartesianNorm() const;

    std::string toString() const;

    SVector& transpose();
    bool containsOnlyZeros()const;
    bool operator==(const SVector&)const;
    SVector& operator = (const SVector&);
    const SVector& operator -();
private:
    std::vector<double> _vector;
    Logger& _log;
    bool _colummnVector;


    friend SVector operator *(const SVector&, double);
    friend SVector operator *(double,const SVector&);
    friend SVector operator *(const SVector&, int);
    friend SVector operator *(int,const SVector&);
    friend std::optional<double> operator *(const SVector&, const SVector&);
    friend SVector operator +(const SVector&, const SVector&);
    friend SVector operator -(const SVector&, const SVector&);

};

std::optional<double> operator *(const SVector&, const SVector&);
SVector operator *(const SVector&, double);
SVector operator *(double,const SVector&);
SVector operator *(const SVector&, int);
SVector operator *(int,const SVector&);
SVector operator +(const SVector&, const SVector&);
SVector operator -(const SVector&, const SVector&);

#endif //SOLVERTESTS_VECTOR_HPP
