//
// Created by maciek on 05.05.19.
//

#ifndef THEORY_AND_METHODS_OF_OPTIMIZATION_FUNCTIONSSAVER_HPP
#define THEORY_AND_METHODS_OF_OPTIMIZATION_FUNCTIONSSAVER_HPP

#include <string>
#include <vector>

class Logger;

class FunctionsSaver
{
public:
    FunctionsSaver();
    explicit FunctionsSaver(const std::string& filename);
    const std::vector<std::pair<std::string, std::string>> readFunctions();
    void saveFunction(const std::string&);
    const std::string getFunctionWithIndex(int) const;
private:
    std::string _filename{"functions.txt"};
    Logger& _log;
    std::vector<std::pair<std::string, std::string>> _standardFunctions
        {{  "Paraboloid", "x1^2+x2^2"}
         , {"Rosenbrock's Function", "100*(x2-x1^2)^2+(1-x1)^2"}
         , {"Three-Hump Camel Function", "(2*x1^2)-(1.05*x1^4)+(x1^6)/6+x1*x2+(x2^2)"}
         , {"Six-Hump Camel Function", "4*x1^2 - 2.1*x1^4 + (x1^6)/3 +x1*x2 - 4*x2^2+4*x2^4"}
         , {"Zangwill's Function", "(x1-x2+x3)^2+(-x1+x2+x3)^2+(x1+x2-x3)^2"}
         , {"4 local minimums", "(x1)^4+(x2)^4-0.62*x1^2-0.62*x2^2"}
         , {"Modified Himmelblau's Function", "(x1^2+x2-11)^2+(x1+x2^2-7)^2-200"}
         , {"Test Function 1", "sin(x1)*(sin(x2)*exp(-(x1^2+x2^2)))"}
         , {"Test Function 2", "x1*exp(-(x1^2+x2^2))"}
        };;
};

#endif //THEORY_AND_METHODS_OF_OPTIMIZATION_FUNCTIONSSAVER_HPP
