//
// Created by diego on 6/28/21.
//

#pragma once

#include <iostream>

#if WIN32
#include <windows.h> // Windows header API
#endif


class Log
{
public:
    static void info(const char *message);
    static void warn(const char* warning);
    static void error(const char* error);

    static void initLogFile(); // start a new clean log file

private:
    static void writeToLogFile(const char* type, const char* msg);
};

