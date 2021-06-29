//
// Created by diego on 6/28/21.
//

#pragma once

#include <iostream>

class Log
{
public:
    static void info(const char *message);
    static void warn(const char* warning);
    static void error(const char* error);
};

