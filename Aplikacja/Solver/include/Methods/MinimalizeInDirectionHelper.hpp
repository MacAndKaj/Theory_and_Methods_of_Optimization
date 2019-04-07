//
// Created by maciek on 07.04.19.
//

#ifndef SOLVER_MINIMALIZERINDIRECTION_HPP
#define SOLVER_MINIMALIZERINDIRECTION_HPP

#include <memory>

class FunctionWrapper;
class SVector;
class Logger;

class MinimalizeInDirectionHelper
{
public:
    MinimalizeInDirectionHelper();
    explicit MinimalizeInDirectionHelper(const std::shared_ptr<FunctionWrapper>& functionWrapper);

    void setFunctionWrapper(const std::shared_ptr<FunctionWrapper>& functionWrapper);
    float getAlfa(const SVector& direction,const SVector& point) const;
private:
    std::shared_ptr<FunctionWrapper> _functionWrapper;
    Logger& _log;
};

#endif //SOLVER_MINIMALIZERINDIRECTION_HPP
