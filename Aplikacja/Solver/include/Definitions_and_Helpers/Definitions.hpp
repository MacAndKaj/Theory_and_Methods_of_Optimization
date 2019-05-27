//
// Created by maciek on 08.03.19.
//

#ifndef SOLVER_DEFINITIONS_HPP
#define SOLVER_DEFINITIONS_HPP

#include <iostream>

const unsigned int defaultIterationsNumber = 20;
const double defaultSolutionGradientError = 1e-10;
const double defaultSolutionStepError = 1e-10;
const double defaultSolutionValueError = 1e-10;
const double defaultArmijoMethodParameter = 0.5;

enum class MethodType
{
    MethodType_Unknown = 0,
    MethodType_PolakRibiere = 1
};


std::ostream& operator << (std::ostream& strm,MethodType methodType);



#endif //SOLVER_DEFINITIONS_HPP
