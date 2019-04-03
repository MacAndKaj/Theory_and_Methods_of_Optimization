//
// Created by maciek on 19.03.19.
//

#ifndef FUNCTIONGETTER_IFUNCTIONGETTER_HPP
#define FUNCTIONGETTER_IFUNCTIONGETTER_HPP

#include <memory>
#include <string>

class FunctionWrapper;

class IFunctionsFactory
{
public:
    virtual std::shared_ptr<FunctionWrapper> parseStringToSFunction(const std::string&,
        unsigned int) = 0;
};

#endif //FUNCTIONGETTERTESTS_IFUNCTIONGETTER_HPP
