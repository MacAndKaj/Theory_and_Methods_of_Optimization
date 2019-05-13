//
// Created by maciek on 23.04.19.
//

#ifndef THEORY_AND_METHODS_OF_OPTIMIZATION_SOLVERWRAPPER_HPP
#define THEORY_AND_METHODS_OF_OPTIMIZATION_SOLVERWRAPPER_HPP

#include <QWidget>
#include <memory>

#include <Definitions_and_Helpers/Definitions.hpp>
#include <Solver.hpp>
#include <ApplicationStorage.hpp>
#include <Solver/include/FunctionInPointParameters.hpp>
#include <Solver/include/Methods/IterationMethodsParameters.hpp>



class SolverWrapper : public QWidget
{
Q_OBJECT
public:
    SolverWrapper();
    void startComputing();

    void setFunction(unsigned int, const std::string&);
    void setAlgorithmParameters(const IterationMethodsParameters&);
    void setMethod(MethodType);
    void setStartPoint(const SVector&);
    SSolution getSolution() const;
    unsigned int getProblemDimension()const;
    std::shared_ptr<FunctionWrapper> getFunction()const;

signals:
    void iterationDone(const FunctionInPointParameters&);

private:
    std::shared_ptr<IApplicationStorage> _applicationStorage;
    std::unique_ptr<ISolver> _solver;
    unsigned int _dimension;
};

#endif //THEORY_AND_METHODS_OF_OPTIMIZATION_SOLVERWRAPPER_HPP
