//
// Created by maciek on 19.03.19.
//

#ifndef FUNCTIONGETTER_IFUNCTIONGETTER_HPP
#define FUNCTIONGETTER_IFUNCTIONGETTER_HPP

#include <memory>
#include <string>

class FunctionWrapper;
class GradientWrapper;
class HessianWrapper;

class IFunctionsFactory
{
public:
    virtual std::shared_ptr<FunctionWrapper> getFunctionFromString(
        const std::string&, unsigned int) = 0;
    virtual std::shared_ptr<GradientWrapper> getGradientForFunction(
        const std::shared_ptr<FunctionWrapper>&) = 0;
    virtual std::shared_ptr<HessianWrapper> getHessianForGradient(
        std::shared_ptr<GradientWrapper>) = 0;
};

#endif //FUNCTIONGETTERTESTS_IFUNCTIONGETTER_HPP
