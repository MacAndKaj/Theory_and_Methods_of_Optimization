//
// Created by maciek on 08.03.19.
//

#ifndef SOLVER_DEFINITIONS_HPP
#define SOLVER_DEFINITIONS_HPP

unsigned int defaultIterationsNumber = 100;
float defaultSolutionError = 1e-3;
float defaultSolutionError1 = 1e-3;
float defaultSolutionError2 = 1e-3;

enum class MethodType
{
    MethodType_Unknown = 0,
    MethodType_PolakRibiere = 1,
};
enum class ParameterType
{
    ParameterType_Unkown = 1;
    ParameterType_Iterations = 1;
    ParameterType_SolutionError = 1;
};

#endif //SOLVER_DEFINITIONS_HPP
