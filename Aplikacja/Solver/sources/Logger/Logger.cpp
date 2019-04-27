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
        auto type = msg[0];
        auto msgIterator = msg.begin();
        if (type == 'D' or type == 'W' or type == 'I' or type == 'E')
        {
            ++msgIterator;
        }
        auto message = std::string{msgIterator,msg.end()};
        if(type == 'I')
        {
            _log->info(message);
        }
        else if(type =='W')
        {
            _log->warn(message);
        }
        else if(type =='E')
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

