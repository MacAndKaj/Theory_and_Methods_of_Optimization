//
// Created by maciek on 06.04.19.
//

#include <Functions/HessianWrapper.hpp>
#include <SMatrix.hpp>
#include <Logger/LoggersFactory.hpp>
#include <SVector.hpp>

HessianWrapper::HessianWrapper(const std::shared_ptr<GradientWrapper>& gradient,
    const std::shared_ptr<IApplicationStorage>& applicationStorage)
    : _log(LoggersFactory::getLoggersFactory()
               .getLogger("HessianWrapper[" + gradient->getOriginalFunction() + "]"))
{

}

std::optional <SMatrix> HessianWrapper::getHessianInPoint(const SVector& point)
{
    std::vector<std::vector<float>> matrixReturned(point.getSize());
    auto returnedMatrixRowsIter = matrixReturned.begin();
    for (const auto& rows : _hessianMatrix)
    {
        returnedMatrixRowsIter->reserve(point.getSize());
        auto returnedMatrixColsIter = returnedMatrixRowsIter->begin();
        for (const auto& col_item : rows)
        {
            (*returnedMatrixColsIter) = (*col_item->operator()(point));
            ++returnedMatrixColsIter;
        }
        ++returnedMatrixRowsIter;
    }

    return {SMatrix()};
}
