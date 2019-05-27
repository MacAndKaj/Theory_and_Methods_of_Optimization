//
// Created by maciek on 17.03.19.
//

#include <Logger/Logger.hpp>
#include <spdlog/sinks/rotating_file_sink.h>
#include <iostream>
#include <sstream>

Logger::Logger(const std::string& loggerName,
    const std::shared_ptr<spdlog::sinks::basic_file_sink_mt>& fileSink)
    : _loggingEnabled(false)
{
    if (fileSink)
    {
        _log = std::make_unique<spdlog::logger>(loggerName, fileSink);
        _loggingEnabled = true;
    }
}

Logger& Logger::operator <<(const std::string& msg)
{

    if (not _loggingEnabled)
    {
        std::cout << msg << std::endl;
    }
    else if (not msg.empty() and _log)
    {
        auto type = msg[0];
        auto msgIterator = msg.begin();
        if (type == 'D' or type == 'W' or type == 'I' or type == 'E')
        {
            ++msgIterator;
        }
        auto message = std::string{msgIterator, msg.end()};
        if (type == 'I')
        {
            _log->info(message);
        }
        else if (type == 'W')
        {
            _log->warn(message);
        }
        else if (type == 'E')
        {
            _log->error(message);
        }
        else
        {
            _log->debug(message);
        }
    }
    return *this;
}


