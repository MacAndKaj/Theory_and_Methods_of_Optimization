//
// Created by maciek on 17.03.19.
//

#ifndef SOLVER_LOGGER_HPP
#define SOLVER_LOGGER_HPP

#include <spdlog/logger.h>

class LoggersFactory;

class Logger
{
public:
    Logger() = delete;
    Logger& operator <<(const std::string&);
private:
    explicit Logger(const std::string&);

    bool _loggingEnabled;
    std::shared_ptr<spdlog::logger> _log;
    friend class LoggersFactory;
};

#endif //SOLVER_LOGGER_HPP
