//
// Created by maciek on 24.03.19.
//

#ifndef SOLVER_PYTHONFILEHELPER_HPP
#define SOLVER_PYTHONFILEHELPER_HPP

#include <string>


class PythonFileHelper
{
public:
    explicit PythonFileHelper(std::string&&);
    std::string createPythonScript(const std::string&, unsigned int) const;
private:
    std::string getBegingOfFile()const;
    std::string getSymbolsForDerivative(unsigned int) const;
    std::string getWriteFunctions(unsigned int) const;
    std::string changePowerOperators(const std::string&)const;
    std::string _filename;
};

#endif //SOLVER_PYTHONFILEHELPER_HPP
