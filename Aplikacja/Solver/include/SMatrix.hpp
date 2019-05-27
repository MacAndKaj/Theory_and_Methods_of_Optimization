//
// Created by maciek on 06.03.19.
//

#ifndef SOLVER_MATRIX_HPP
#define SOLVER_MATRIX_HPP

#include <vector>
#include <optional>

class Logger;

class SMatrix
{
public:
    SMatrix();
    explicit SMatrix(const std::vector<std::vector<double>>& vector);

    const std::vector<std::vector<double>>& getVector() const;
    void setVector(const std::vector<std::vector<double>>& vector);
    std::optional<double> getMinor(unsigned int&) const;
    bool operator==(const SMatrix&)const;
    bool operator!=(const SMatrix&)const;
    const SMatrix& operator -();
    std::string toString() const;
    std::optional<double> det() const;
    std::vector<double> getSubDeterminants() const;

private:
    /// First-number of rows, Second-number of columns
    std::pair<unsigned int,unsigned int> _dimension;
    std::vector<std::vector<double>> _vector;
    Logger& _log;

    friend SMatrix operator *(const SMatrix&, double);
    friend SMatrix operator *(const SMatrix&, const SMatrix&);
    friend SMatrix operator +(const SMatrix&, const SMatrix&);
    friend SMatrix operator -(const SMatrix&, const SMatrix&);

};

SMatrix operator *(const SMatrix&, double);
SMatrix operator *(const SMatrix&, const SMatrix&);
SMatrix operator +(const SMatrix&, const SMatrix&);
SMatrix operator -(const SMatrix&, const SMatrix&);

#endif //SOLVER_MATRIX_HPP
