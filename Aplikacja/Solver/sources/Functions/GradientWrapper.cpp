//
// Created by maciek on 03.04.19.
//

#include <Functions/GradientWrapper.hpp>
#include <IApplicationStorage.hpp>
#include <SymbolicOperations/ISymbolicOperator.hpp>
#include <SVector.hpp>
#include <Logger/LoggersFactory.hpp>


GradientWrapper::GradientWrapper(const std::shared_ptr<FunctionWrapper>& function,
    const std::shared_ptr<IApplicationStorage>& applicationStorage)
    : _log(LoggersFactory::getLoggersFactory()
               .getLogger("GradientWrapper[" + function->getExpressionString() + "]"))
{
    _originalFunction = function->getExpressionString();
    _gradientVector = applicationStorage->getSymbolicOperator()->getDerivatives(function);
}

std::optional<SVector> GradientWrapper::getGradientInPoint(const SVector& point)
{
    if (point.getSize() != _gradientVector.size())
    {
        _log << "Point dimension or gradient size not correct!";
        return {};
    }
    std::vector<float> _computedGradient;
    _computedGradient.reserve(point.getSize());
    for (const auto& item : _gradientVector)
    {
        auto gradientItemInPoint = item->operator()(point);
        if(not gradientItemInPoint)
        {
            _log << "Problem when extracting value of gradient by one of the variables in point!";
            return SVector();
        }
        _computedGradient.push_back(*gradientItemInPoint);
    }


    return {SVector(_computedGradient)};
}

const std::string& GradientWrapper::getOriginalFunction() const
{
    return _originalFunction;
}

const std::vector<std::string> GradientWrapper::getGradientSymbolicForm() const
{
    std::vector<std::string> returnedVector(_gradientVector.size());

    std::for_each(_gradientVector.cbegin(),_gradientVector.cend(), [&returnedVector](const auto& item){
        returnedVector.push_back(item->getExpressionString());
    });
    return returnedVector;
}
