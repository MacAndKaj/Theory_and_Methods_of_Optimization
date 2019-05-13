//
// Created by maciek on 05.05.19.
//

#include <filesystem>
#include <Solver/include/Logger/LoggersFactory.hpp>
#include "FunctionsSaver.hpp"



FunctionsSaver::FunctionsSaver(const std::string& filename)
    : filename(filename)
    , _log(LoggersFactory::getLoggersFactory().getLogger("FunctionSaver"))
{

}

FunctionsSaver::FunctionsSaver()
    : _log(LoggersFactory::getLoggersFactory().getLogger("FunctionSaver"))
{

}

const std::vector<std::pair<std::string, std::string>> FunctionsSaver::readFunctions()
{
    return _standardFunctions;
}

void FunctionsSaver::saveFunction(const std::string&)
{

}

const std::string FunctionsSaver::getFunctionWithIndex(int index) const
{
    return _standardFunctions[index].second;
}
