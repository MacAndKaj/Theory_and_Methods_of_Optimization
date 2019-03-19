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
    explicit SMatrix(const std::vector<std::vector<float>>& vector);

    std::optional<float> getMinor(unsigned int&) const;
    bool operator==(const SMatrix&)const;
private:
    std::pair<unsigned int,unsigned int> _dimension;
    std::vector<std::vector<float>> _vector;
    Logger& _log;

};

#endif //SOLVER_MATRIX_HPP
