//
// Created by maciek on 19.03.19.
//

#ifndef FUNCTIONGETTER_IFUNCTIONGETTER_HPP
#define FUNCTIONGETTER_IFUNCTIONGETTER_HPP

#include <bits/shared_ptr.h>
#include <string>

class SFunction;
class SObjectiveFunction;


class IObjectiveFunctionGetter
{
public:
    virtual std::shared_ptr<SFunction> parseStringToSFunction(const std::string&) = 0;
    virtual std::shared_ptr<SObjectiveFunction> parseStringToSObjectiveFunction(const std::string&) = 0;

};

#endif //FUNCTIONGETTERTESTS_IFUNCTIONGETTER_HPP
