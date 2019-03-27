//
// Created by maciek on 19.03.19.
//

#include <memory>
#include <FunctionGetter/ObjectiveFunctionGetter.hpp>

std::shared_ptr<SFunction>
ObjectiveFunctionGetter::parseStringToSFunction(const std::string& string)
{
    return std::shared_ptr<SFunction>();
}

std::shared_ptr<SObjectiveFunction>
ObjectiveFunctionGetter::parseStringToSObjectiveFunction(const std::string& string)
{
    return std::shared_ptr<SObjectiveFunction>();
}
