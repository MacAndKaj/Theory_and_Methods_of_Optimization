//
// Created by maciek on 17.03.19.
//

#ifndef SOLVER_LOGGER_HPP
#define SOLVER_LOGGER_HPP

#include <spdlog/sinks/basic_file_sink.h>

class LoggersFactory;

class Logger
{
public:
    Logger() = delete;
    Logger& operator <<(const std::string&);
private:
    Logger(const std::string&, const std::shared_ptr<spdlog::sinks::basic_file_sink_mt>&);

    bool _loggingEnabled;
    std::shared_ptr<spdlog::logger> _log;
    friend class LoggersFactory;
};

#endif //SOLVER_LOGGER_HPP
