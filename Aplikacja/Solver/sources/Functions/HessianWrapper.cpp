//
// Created by maciek on 06.04.19.
//

#include <SMatrix.hpp>
#include <SVector.hpp>
#include <Logger/LoggersFactory.hpp>
#include <Functions/HessianWrapper.hpp>
#include <ApplicationStorage.hpp>
#include <SymbolicOperations/SymbolicOperator.hpp>
#include <iostream>

HessianWrapper::HessianWrapper(const std::shared_ptr<GradientWrapper>& gradient,
    const std::shared_ptr<IApplicationStorage>& applicationStorage)
    : _log(LoggersFactory::getLoggersFactory()
               .getLogger("HessianWrapper[" + gradient->getOriginalFunction() + "]"))
{
    for (const auto& gradientSymbolicForm : gradient->getGradient())
    {
        _hessianMatrix.emplace_back(
            applicationStorage->getSymbolicOperator()->getDerivatives(gradientSymbolicForm));
    }
}

std::optional<SMatrix> HessianWrapper::getHessianInPoint(const SVector& point)
{

    std::vector<std::vector<double>> matrixReturned;
    for (const auto& rows : _hessianMatrix)
    {
        std::vector<double> temp;
        for (const auto& col_item : rows)
        {
            temp.emplace_back(*col_item->operator ()(point));
        }
        matrixReturned.emplace_back(temp);
    }

    return {SMatrix(matrixReturned)};
}
