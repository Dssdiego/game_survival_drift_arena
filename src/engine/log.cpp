//
// Created by diego on 6/28/21.
//

#include "log.h"
#include "constants.h"

#define RESET "\e[0m"
#define COLOR_BLACK "\e[0;30m"
#define COLOR_GRAY "\e[0;37m"
#define COLOR_RED "\e[0;91m"
#define COLOR_GREEN "\e[0;92m"
#define COLOR_YELLOW "\e[0;93m"
#define COLOR_BLUE "\e[0;94m"
#define COLOR_PURPLE "\e[0;95m"
#define COLOR_CYAN "\e[0;96m"
#define COLOR_WHITE "\e[0;97m"

void Log::info(const char *message)
{
//    if(CONST_DEBUG){
#ifndef NDEBUG
        std::cout << COLOR_BLUE << "info::" << message << RESET << std::endl;
#endif
//    }
}

void Log::warn(const char *warning)
{
#ifndef NDEBUG
        std::cout << COLOR_YELLOW << "warn::" << warning << RESET << std::endl;
#endif
}

void Log::error(const char *error)
{
#ifndef NDEBUG
        std::cout << COLOR_RED << "error::" << error << RESET << std::endl;
#endif
}
