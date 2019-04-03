//
// Created by maciek on 08.03.19.
//

#ifndef SOLVER_DEFINITIONS_HPP
#define SOLVER_DEFINITIONS_HPP

#include <iostream>

const unsigned int defaultIterationsNumber = 100;
const float defaultSolutionError = 1e-3;
const float defaultSolutionError1 = 1e-3;
const float defaultSolutionError2 = 1e-3;

enum class MethodType
{
    MethodType_Unknown = 0,
    MethodType_PolakRibiere = 1
};

enum class ParameterType
{
    ParameterType_Unkown = 1,
    ParameterType_Iterations = 1,
    ParameterType_SolutionError = 1
};

std::ostream& operator << (std::ostream& strm,MethodType methodType);



#endif //SOLVER_DEFINITIONS_HPP
