#ifndef __MYLOG_H__
#define __MYLOG_H__

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h" 
#include "single_model.h"
#include <stdarg.h>

class Log : public Singleton<Log> {
    friend class Singleton<Log>;
public:
    Log (const Log&) = delete;
    Log& operator = (const Log&) = delete;
protected:
    Log() = default;
public:
    void init(const char* log_name, const char* file){
        __logger = spdlog::basic_logger_mt(log_name, file);        
        spdlog::set_pattern("[%H:%M:%S][%n]<%t> %v");
    }
    template <typename... Args>
    void debug(spdlog::format_string_t<Args...> format_string, Args&&... args){
        __logger.get()->info(format_string, std::forward<Args>(args)...);
        __logger.get()->flush();
    }
    void debug(const char* msg){
        __logger.get()->info(msg);
        __logger.get()->flush();
    }
private:
    std::shared_ptr<spdlog::logger> __logger;
};

#define log_init(logname, filename) Log::get_inst().init(logname, filename)
#define log_debug(fm, ...) Log::get_inst().debug(fm, ##__VA_ARGS__)


#endif