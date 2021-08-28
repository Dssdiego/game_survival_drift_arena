//
// Created by diego on 6/28/21.
//

#include "log.h"
#include "constants.h"

#include <iostream>
#include <fstream>

#include <iomanip>
#include <ctime>
#include <sstream>

#if UNIX
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
#else
#define COLOR_GRAY 8
#define COLOR_RED 12
#define COLOR_GREEN 10
#define COLOR_YELLOW 14
#define COLOR_BLUE 9
#define COLOR_PURPLE 13
#define COLOR_CYAN 11
#define COLOR_WHITE 7
#endif

void Log::info(const char *message)
{
#ifndef NDEBUG
#if UNIX
    std::cout << COLOR_BLUE << "info::" << message << RESET << std::endl;
#else
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_BLUE);
    std::cout << "info::" << message << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_WHITE);
#endif

    writeToLogFile("info::", message);
#endif
}

void Log::warn(const char *warning)
{
#ifndef NDEBUG
#if UNIX
    std::cout << COLOR_YELLOW << "warn::" << warning << RESET << std::endl;
#else
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_YELLOW);
    std::cout << "warn::" << warning << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_WHITE);
#endif
    writeToLogFile("warn::", warning);
#endif
}

void Log::error(const char *error)
{
#ifndef NDEBUG
#if UNIX
    std::cout << COLOR_RED << "error::" << error << RESET << std::endl;
#else
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_RED);
    std::cout << "error::" << error << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_WHITE);
#endif
    writeToLogFile("error::", error);
#endif
}

void Log::initLogFile()
{
    std::ofstream logFile;
    logFile.open("logfile.txt");
    logFile << "";
    logFile.close();
}

void Log::writeToLogFile(const char* type, const char *msg)
{
    // REVIEW: This could be leaking memory!
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    auto timeStr = oss.str();

    std::string buf("");
    buf.append(timeStr);
    buf.append("\t");
    buf.append(type);
    buf.append(msg);

    std::ofstream logFile;
    logFile.open("logfile.txt", std::ios_base::app);
    logFile << buf << "\n";
}
