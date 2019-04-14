//
// Created by maciek on 08.03.19.
//

#ifndef SOLVER_DEFINITIONS_HPP
#define SOLVER_DEFINITIONS_HPP

#include <iostream>

const unsigned int defaultIterationsNumber = 200;
const double defaultSolutionError = 1e-20;
const double defaultSolutionError1 = 1e-20;
const double defaultSolutionError2 = 1e-20;

enum class MethodType
{
    MethodType_Unknown = 0,
    MethodType_PolakRibiere = 1
};


std::ostream& operator << (std::ostream& strm,MethodType methodType);



#endif //SOLVER_DEFINITIONS_HPP
