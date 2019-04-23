//
// Created by maciek on 10.04.19.
//

#include <iostream>
#include <Methods/MethodsFactory.hpp>
#include <Definitions_and_Helpers/Definitions.hpp>
#include <SVector.hpp>
#include <Methods/IMethod.hpp>
#include <ApplicationStorage.hpp>
#include <Functions/FunctionsFactory.hpp>

//std::string function = "(x1)^2+(x2)^2";
//std::string function = "(x1-x2+x3)^2+(-x1+x2+x3)^2 + (x1+x2-x3)^2";
//std::string function = "(x1)^4+(x2)^4-0.62*(x1)^2-0.62*(x2)^2";
//std::string function = "((x1)^2+(x2)-11)^2+(x1+(x2)^2-7)^2-200";
std::string function = "4*(x1)^2-2.1*(x1)^4+(1/3)*(x1)^6+x1*x2-4*(x2)^2+4*(x2)^4";
//std::string function = "(x1-2)^2+(x1-(x2)^2)^2";
//unsigned int dimension = 3;
unsigned int dimension = 2;
//SVector startingPoint({100, -1,2.5});
SVector startingPoint({1,-3});

int main()
{
    auto storage = std::make_shared<ApplicationStorage>();

    std::vector<SVector> solution = {startingPoint};
    auto metoda = storage->getMethodsFactory()->getPolakRibiereMethod(
        defaultSolutionError, defaultSolutionError1, defaultSolutionError2,
        1000, {solution});

    auto funkcja = storage->getFunctionsFactory()->getFunctionFromString(function, dimension);
    auto gradient = storage->getFunctionsFactory()->getGradientForFunction(funkcja);
    metoda->setFunction(funkcja);
    metoda->setGradient(gradient);
    metoda->startComputing();

}
