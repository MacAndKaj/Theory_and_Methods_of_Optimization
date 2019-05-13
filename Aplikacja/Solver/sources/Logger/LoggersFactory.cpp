//
// Created by maciek on 17.03.19.
//

#include <Logger/LoggersFactory.hpp>
#include <fstream>
#include <spdlog/sinks/basic_file_sink.h>
#include <iostream>

std::unique_ptr<LoggersFactory> LoggersFactory::_instance;
std::once_flag LoggersFactory::_onceFlag;


LoggersFactory::LoggersFactory()
    : _logToFile(true)
{
    std::fstream file("log.txt",std::ios::out | std::ios::trunc);
    file.close();
    try
    {
        _logger = std::make_shared<spdlog::sinks::basic_file_sink_mt>("log.txt");
    }
    catch (...)
    {
        std::cerr << "Logging to file disabled! Logging on std output!" << std::endl;
        _logToFile = false;
    }
}

LoggersFactory& LoggersFactory::getLoggersFactory()
{

    std::call_once(LoggersFactory::_onceFlag, [](){
        _instance.reset(new LoggersFactory);
    });

    return *_instance;
}

Logger& LoggersFactory::getLogger(const std::string& loggerName)
{
    if(not loggerExists(loggerName))
        _loggersMap[loggerName] = std::unique_ptr<Logger>(new Logger(loggerName,_logger));
    return *_loggersMap[loggerName];
}

bool LoggersFactory::loggerExists(const std::string& loggerName) const
{
    return _loggersMap.end() != std::find_if(_loggersMap.begin(),_loggersMap.end(),[loggerName](const auto& pair){
        return pair.first == loggerName;
    });

}
