//
// Created by maciek on 06.03.19.
//

#ifndef SOLVER_ISOLVER_HPP
#define SOLVER_ISOLVER_HPP

#include <string>
#include <Definitions_and_Helpers/Definitions.hpp>


class SSolution;

class ISolver
{
public:
    virtual void setMethod(MethodType) = 0;
    virtual void setAlgorithmParameters() = 0;
    virtual void setFunction(const unsigned int&,const std::string&) = 0;
    virtual void computeSolution() = 0;
    virtual SSolution getSolution() const = 0;
};

#endif //SOLVER_ISOLVER_HPP
