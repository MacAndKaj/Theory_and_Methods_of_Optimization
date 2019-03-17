//
// Created by maciek on 16.03.19.
//

#ifndef SOLVER_SGRADIENT_HPP
#define SOLVER_SGRADIENT_HPP

#include <functional>
#include <vector>
#include <Definitions_and_Helpers/Optional.hpp>

class Logger;
class SVector;

class SGradient
{
    using Function = std::function<float (SVector&)>;
public:
    SGradient() = delete;
    explicit SGradient(const std::vector<Function>& gradientVector);

    Optional<SVector> operator()(SVector&) const;
private:
    unsigned int _dimension;
    std::vector<Function> _gradientVector;
    Logger& _log;
};

#endif //SOLVER_SGRADIENT_HPP
