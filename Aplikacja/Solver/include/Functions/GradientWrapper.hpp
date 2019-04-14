//
// Created by maciek on 03.04.19.
//

#ifndef SOLVER_GRAGIENTWRAPPER_HPP
#define SOLVER_GRAGIENTWRAPPER_HPP

#include "FunctionWrapper.hpp"

class IApplicationStorage;
class SVector;

class GradientWrapper
{
public:
    GradientWrapper() = delete;
    GradientWrapper(const std::shared_ptr<FunctionWrapper>&,
        const std::shared_ptr<IApplicationStorage>& applicationStorage);

    const std::vector<std::string> getGradientSymbolicForm() const;
    std::optional<SVector> getGradientInPoint(const SVector&);
    const std::string& getOriginalFunction() const;
    unsigned int getDimension() const;
private:
    std::string _originalFunction;
    std::vector<std::shared_ptr<FunctionWrapper>> _gradientVector;
    Logger& _log;
};

#endif //SOLVER_GRAGIENTWRAPPER_HPP
