//
// Created by maciek on 24.03.19.
//

#include <SymbolicOperations/PythonFileHelper.hpp>
#include <fstream>
#include <vector>
#include <iostream>

PythonFileHelper::PythonFileHelper(std::string&& filename)
    : _filename(filename)
{

}

std::string PythonFileHelper::createPythonScript(const std::string& fun, unsigned int dim) const
{
    std::ofstream file("tempScript.py", std::ios::out);
    if (file.good())
    {
        file << getBegingOfFile();
        file << getSymbolsForDerivative(dim);
        file << "fun = " + changePowerOperators(fun) + "\n";
        file << getWriteFunctions(dim);
        file << "fileForEquetions.close()";
        file.close();
        return "tempScript.py";
    }
    return "";
}

std::string PythonFileHelper::getBegingOfFile() const
{
    return "from sympy import *\n"
           "fileForEquetions = open('" + _filename + "', 'w')\n";
}

std::string PythonFileHelper::getSymbolsForDerivative(unsigned int dimension) const
{
    std::string leftside, rightside{"=symbols('"};
    for (int i = 1; i <= dimension; ++i)
    {
        auto x = "x" + std::to_string(i);
        leftside += (x + ',');
        rightside += (x + ' ');
    }
    return leftside + rightside + "')\n";
}

std::string PythonFileHelper::getWriteFunctions(unsigned int dimension) const
{
    std::string begin{"fileForEquetions.write(diff(fun,"}, end{").__str__()+'\\n')\n"};
    std::string ret;
    for (int i = 1; i <= dimension; ++i)
    {

        ret += begin;
        ret += "x" + std::to_string(i);
        ret += end;

    }
    return ret;
}

std::string PythonFileHelper::changePowerOperators(const std::string& fun) const
{
    std::string ret;
    for (char i : fun)
    {
        if (i == '^') ret += ("**");
        else ret += i;
    }
    return ret;
}

