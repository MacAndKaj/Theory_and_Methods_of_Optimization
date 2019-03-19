//
// Created by maciek on 19.03.19.
//

#ifndef SOLVER_PARSERWRAPPER_HPP
#define SOLVER_PARSERWRAPPER_HPP

#include <Functions/FunctionWrapper.hpp>

class SVector;

class ParserWrapper
{
public:
    ParserWrapper();
    std::shared_ptr<FunctionWrapper> parseToFunction(unsigned int, const std::string&);
private:
    exprtk::parser<float> _parser;
};

#endif //SOLVER_PARSERWRAPPER_HPP
