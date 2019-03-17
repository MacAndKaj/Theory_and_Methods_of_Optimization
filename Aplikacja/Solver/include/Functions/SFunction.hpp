//
// Created by maciek on 16.03.19.
//

#ifndef SOLVER_SFUNCTION_HPP
#define SOLVER_SFUNCTION_HPP

#include <functional>
#include <Definitions_and_Helpers/Optional.hpp>
#include <Logger/Logger.hpp>

class SVector;

class SFunction
{
public:

    SFunction() = delete;
    SFunction(unsigned int& dimension, const std::function<float(SVector&)>& func);

    unsigned int getDimension() const;
    Optional<float> operator ()(SVector&) const;
private:
    unsigned int _dimension;
    std::function<float(SVector&)> _func;
    Logger& _log;
};

#endif //SOLVER_SFUNCTION_HPP
