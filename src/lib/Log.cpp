// File: Log.cpp
// Author: DP-Dev
// Implementation of the log class.
#include <CPGE/Log.hpp>
#include <cstdarg>
using namespace CPGE;
using namespace std;

// Print a message with LogCategory::APPLICATION and LogCategory::INFO.
void Log::print(const string fmt, ...)
{
  // Variable to handle arguments.
  va_list arguments;
  // Initialize the argument's list.
  va_start(arguments, fmt);
  // Pass to SDL_LogMessageV().
  SDL_LogMessageV(static_cast<SDL_LogCategory>(LogCategory::APPLICATION),
    static_cast<SDL_LogPriority>(LogPriority::INFO), fmt.c_str(), arguments);
  // Deinitialize the argument's list.
  va_end(arguments);
}

// Prints a string.
void Log::printString(const std::string &str)
{
  SDL_Log("%s", str.c_str());
}

// Prints a string followed by a newline.
void Log::printLine(const string &str)
{
  SDL_Log("%s", str.c_str());
}
