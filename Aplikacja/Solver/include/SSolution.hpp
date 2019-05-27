//
// Created by maciek on 07.03.19.
//

#ifndef SOLVER_SSOLUTION_HPP
#define SOLVER_SSOLUTION_HPP

#include <vector>
#include "SVector.hpp"

class SSolution
{
public:
    explicit SSolution(std::vector<SVector>  points,double value);
    void addNewPoint(const SVector&,double value);
    SVector getLastPoint() const;
    SVector getSecondLastPoint() const;
    int getSize() const;
    std::vector<std::pair<SVector, double>> getSolutionAsMap() const;

private:
    std::vector<SVector> _points;
    std::vector<double> _values;
};

#endif //SOLVER_SSOLUTION_HPP
