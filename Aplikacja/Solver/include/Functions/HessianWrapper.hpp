//
// Created by maciek on 06.04.19.
//

#ifndef SOLVER_HESSIANWRAPPER_HPP
#define SOLVER_HESSIANWRAPPER_HPP

#include "GradientWrapper.hpp"

class SMatrix;
class IApplicationStorage;

using FunctionPtr = std::shared_ptr<FunctionWrapper>;
using HessianMatrix = std::vector<std::vector<FunctionPtr>>;

class HessianWrapper
{
public:
    HessianWrapper() = delete;
    HessianWrapper(const std::shared_ptr<GradientWrapper>&,
        const std::shared_ptr<IApplicationStorage>&);

    std::optional<SMatrix> getHessianInPoint(const SVector&);
private:
    std::vector<std::string> _gradientsByVariables;
    HessianMatrix _hessianMatrix;
    Logger& _log;
};

#endif //SOLVER_HESSIANWRAPPER_HPP
