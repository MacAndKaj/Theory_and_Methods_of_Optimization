//
// Created by maciek on 16.03.19.
//

#ifndef SOLVER_SHESSIAN_HPP
#define SOLVER_SHESSIAN_HPP

#include <SVector.hpp>

class SMatrix;

class SHessian
{
    using Function = std::function<float(SVector&)>;
public:
    SHessian() = delete;
    explicit SHessian(const std::vector<std::vector<Function>>& hessianMatrix);

    const std::pair<unsigned int, unsigned int>& getDimension() const;
    std::optional<SMatrix> operator ()(SVector&) const;
private:
//                 Hessian form
//                            vector<vector>
//       __________________________/\___________________________
//      /                                                       \
//      vector<Function>  vector<Function>  ...  vector<Function>
//            |                   |                     |
//            |                   |                     |
//            V                   V                     V
//       | df/dx2x1           df/dx2x2      ...     df/dx2xn |
//       | .                                            .    |
//       | df/dx1x1           df/dx1x2      ...     df/dx1xn |
//       | .                                            .    |
//       | .                                            .    |
//       | df/dxnx1           df/dxnx2      ...     df/dxnxn |

    std::pair<unsigned int,unsigned int> _dimension;
    std::vector<std::vector<Function>> _hessianMatrix;
    Logger& _log;
};

#endif //SOLVER_SHESSIAN_HPP
