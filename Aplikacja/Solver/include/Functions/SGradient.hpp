//
// Created by maciek on 16.03.19.
//

#ifndef SOLVER_SGRADIENT_HPP
#define SOLVER_SGRADIENT_HPP

#include <functional>
#include <vector>

class Logger;
class SVector;

class SGradient
{
    using Function = std::function<float (SVector&)>;
public:
    SGradient() = delete;
    explicit SGradient(const std::vector<Function>& gradientVector);

    std::optional<SVector> operator()(SVector&) const;
private:
//  Gradient(Jakobian of single function) form
//    [ df/dx1 df/dx2 ... df/dxn ]

    unsigned int _dimension;
    std::vector<Function> _gradientVector;
    Logger& _log;
};

#endif //SOLVER_SGRADIENT_HPP
