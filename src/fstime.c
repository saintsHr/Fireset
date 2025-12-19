#define _POSIX_C_SOURCE 199309L

#include "fireset/fstime.h"
#include <stdint.h>

#if defined(_WIN32)

#include <windows.h>

double fsGetSystemTime(void){
    static LARGE_INTEGER freq;
    static int initialized = 0;

    if (!initialized){
        QueryPerformanceFrequency(&freq);
        initialized = 1;
    }

    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);

    return (double)counter.QuadPart / (double)freq.QuadPart;
}

#elif defined(__APPLE__)

#include <mach/mach_time.h>

double fsGetSystemTime(void){
    static mach_timebase_info_data_t timebase;
    static int initialized = 0;

    if (!initialized){
        mach_timebase_info(&timebase);
        initialized = 1;
    }

    uint64_t t = mach_absolute_time();

    return (double)t * (double)timebase.numer / (double)timebase.denom * 1e-9;
}

#elif defined(__linux__)

#include <time.h>

double fsGetSystemTime(void){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec * 1e-9;
}

#else
    #error "OS not supported"
#endif

static double s_last_time = 0.0;

void fsTimeInit(void){
    s_last_time = fsGetSystemTime();
}

double fsGetDeltaTime(void){
    double now = fsGetSystemTime();
    double dt = now - s_last_time;
    s_last_time = now;

    if(dt < 0.0) dt = 0.0;
    if(dt > 0.1) dt = 0.1;
    
    return dt;
}