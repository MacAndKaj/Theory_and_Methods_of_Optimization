//
// Created by maciek on 06.03.19.
//

#ifndef SOLVER_ISOLVER_HPP
#define SOLVER_ISOLVER_HPP

class ISolver
{
public:
    void setMethod() = 0;
    void computeSolution() const = 0;
    SSolution getSolution() const = 0;
};

#endif //SOLVER_ISOLVER_HPP
