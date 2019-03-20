//
// Created by maciek on 17.03.19.
//

#include <Logger/Logger.hpp>
#include <spdlog/details/spdlog_impl.h>

Logger::Logger(const std::string& loggerName)
    : _loggingEnabled(true)
{
    try
    {
        _log = spdlog::basic_logger_mt(loggerName, "log.txt");
    }
    catch (...)
    {
        std::cerr << "Logging to file disabled! Logging on std output!" << std::endl;
        _loggingEnabled = false;
    }
}

Logger& Logger::operator <<(const std::string& msg)
{

    if(not _loggingEnabled)
    {
        std::cout << msg << std::endl;
    }
    else if (not msg.empty() and _log)
    {
        _log->info(msg);
    }

    return *this;
}

