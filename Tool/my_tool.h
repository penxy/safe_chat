#ifndef __MY_TOOL_H__
#define __MY_TOOL_H__
#include <chrono>
#include <stdio.h>

namespace tool_global_timer{
    static std::chrono::_V2::system_clock::time_point start_time;
    static std::chrono::_V2::system_clock::time_point end_time;
    static std::chrono::milliseconds duration;
    void start(){
        start_time = std::chrono::high_resolution_clock::now();
    }
    void end(){
        end_time = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        printf("time: %ldms\n", duration.count());
    }
}



#endif