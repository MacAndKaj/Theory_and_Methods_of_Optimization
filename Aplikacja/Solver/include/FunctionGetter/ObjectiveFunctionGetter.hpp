//
// Created by maciek on 19.03.19.
//

#ifndef SOLVER_OBJECTIVEFUNCTIONGETTER_HPP
#define SOLVER_OBJECTIVEFUNCTIONGETTER_HPP

#include <Interface/IObjectiveFunctionGetter .hpp>
#include <Functions/SObjectiveFunction.hpp>

class ParserWrapper;
class ObjectiveFunctionGetter : public IObjectiveFunctionGetter
{
public:
    std::shared_ptr<SFunction> parseStringToSFunction(const std::string& string) override;
    std::shared_ptr<SObjectiveFunction> parseStringToSObjectiveFunction(
        const std::string& string) override;
private:
    std::unique_ptr<ParserWrapper> _parser;
};

#endif //SOLVER_OBJECTIVEFUNCTIONGETTER_HPP
