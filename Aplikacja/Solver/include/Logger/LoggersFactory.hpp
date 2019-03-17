//
// Created by maciek on 17.03.19.
//

#ifndef SOLVER_LOGGERSFACTORY_HPP
#define SOLVER_LOGGERSFACTORY_HPP

#include <map>
#include <spdlog/sinks/file_sinks.h>
#include "Logger.hpp"

class LoggersFactory
{
public:
    static LoggersFactory& getLoggersFactory();
    Logger& getLogger(const std::string&);

private:
    LoggersFactory();
    bool loggerExists(const std::string&) const;
    static std::unique_ptr<LoggersFactory> _instance;
    static std::once_flag _onceFlag;
    std::map<std::string,std::unique_ptr<Logger>> _loggersMap;
};

#endif //SOLVER_LOGGERSFACTORY_HPP
