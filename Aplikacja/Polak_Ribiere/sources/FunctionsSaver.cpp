//
// Created by maciek on 05.05.19.
//

#include <filesystem>
#include <Solver/include/Logger/LoggersFactory.hpp>
#include <fstream>
#include "FunctionsSaver.hpp"

FunctionsSaver::FunctionsSaver(const std::string& filename)
    : _filename(filename)
    , _log(LoggersFactory::getLoggersFactory().getLogger("FunctionSaver"))
{

}

FunctionsSaver::FunctionsSaver()
    : _filename("inputFunctions.txt")
    , _log(LoggersFactory::getLoggersFactory().getLogger("FunctionSaver"))
{

}

const std::vector<std::pair<std::string, std::string>> FunctionsSaver::readFunctions()
{

    std::ifstream strm(_filename);
    if (strm.is_open())
    {
        std::string buffer;
        while (std::getline(strm, buffer))
        {
            _standardFunctions.emplace_back(std::make_pair("", buffer));
        }
        strm.close();
    }
    return _standardFunctions;
}

void FunctionsSaver::saveFunction(const std::string& function)
{

    std::ofstream strm(_filename, std::ios::app);
    if (strm.is_open())
    {
        strm << function << '\n';
        strm.close();
    }
}

const std::string FunctionsSaver::getFunctionWithIndex(int index) const
{
    return _standardFunctions[index].second;
}
