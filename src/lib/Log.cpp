// File: Log.cpp
// Author: DP-Dev
// Implementation of the log class.
#include <CPGE/Log.hpp>
#include <cstdarg>
using namespace CPGE;
using namespace std;

// Set the reference to the unique instance of the class.
Log &CPGE::theLog = Log::getInstace();

// Print a message with LogCategory::APPLICATION and LogCategory::INFO.
void Log::print(const string fmt, ...)
{
  // Variable to handle arguments.
  va_list arguments;
  // Initialize the argument's list.
  va_start(arguments, fmt);
  // Pass to variadic function.
  this->printMessage(
    LogCategory::APPLICATION, LogPriority::INFO, fmt, arguments);
  // Deinitialize the argument's list.
  va_end(arguments);
}

// Print a string.
void Log::printString(const std::string &str)
{
  this->print("%s", str.c_str());
}

// Print a string followed by a newline.
void Log::printLine(const string &str)
{
  this->print("%s\n", str.c_str());
}

// Print a message with LogCategory::CRITICAL.
void Log::printCritical(const LogCategory &category, const string fmt, ...)
{
  // Variable to handle arguments.
  va_list arguments;
  // Initialize the argument's list.
  va_start(arguments, fmt);
  // Pass to variadic function.
  this->printMessage(category, LogPriority::CRITICAL, fmt, arguments);
  // Deinitialize the argument's list.
  va_end(arguments);
}

// Print a string with LogPriority::CRITICAL priority.
void Log::printCriticalString(
  const LogCategory &category, const std::string &str)
{
  this->printCritical(category, "%s", str.c_str());
}

// Print a string followed by a newline with LogPriority::CRITICAL priority.
void Log::printCriticalLine(const LogCategory &category, const string &str)
{
  this->printCritical(category, "%s\n", str.c_str());
}

// Print a message with LogCategory::DEBUG.
void Log::printDebug(const LogCategory &category, const string fmt, ...)
{
  // Variable to handle arguments.
  va_list arguments;
  // Initialize the argument's list.
  va_start(arguments, fmt);
  // Pass to variadic function.
  this->printMessage(category, LogPriority::DEBUG, fmt, arguments);
  // Deinitialize the argument's list.
  va_end(arguments);
}

// Print a string with LogPriority::DEBUG priority.
void Log::printDebugString(const LogCategory &category, const std::string &str)
{
  this->printDebug(category, "%s", str.c_str());
}

// Print a string followed by a newline with LogPriority::DEBUG priority.
void Log::printDebugLine(const LogCategory &category, const string &str)
{
  this->printDebug(category, "%s\n", str.c_str());
}

// Print a message with LogCategory::ERROR.
void Log::printError(const LogCategory &category, const string fmt, ...)
{
  // Variable to handle arguments.
  va_list arguments;
  // Initialize the argument's list.
  va_start(arguments, fmt);
  // Pass to variadic function.
  this->printMessage(category, LogPriority::ERROR, fmt, arguments);
  // Deinitialize the argument's list.
  va_end(arguments);
}

// Print a string with LogPriority::ERROR priority.
void Log::printErrorString(const LogCategory &category, const std::string &str)
{
  this->printError(category, "%s", str.c_str());
}

// Print a string followed by a newline with LogPriority::ERROR priority.
void Log::printErrorLine(const LogCategory &category, const string &str)
{
  this->printError(category, "%s\n", str.c_str());
}

// Print a message with LogCategory::INFO.
void Log::printInfo(const LogCategory &category, const string fmt, ...)
{
  // Variable to handle arguments.
  va_list arguments;
  // Initialize the argument's list.
  va_start(arguments, fmt);
  // Pass to variadic function.
  this->printMessage(category, LogPriority::INFO, fmt, arguments);
  // Deinitialize the argument's list.
  va_end(arguments);
}

// Print a string with LogPriority::INFO priority.
void Log::printInfoString(const LogCategory &category, const std::string &str)
{
  this->printInfo(category, "%s", str.c_str());
}

// Print a string followed by a newline with LogPriority::INFO priority.
void Log::printInfoLine(const LogCategory &category, const string &str)
{
  this->printInfo(category, "%s\n", str.c_str());
}

// Print a message with a specified category and priority.
void Log::printMessage(const LogCategory &category, const LogPriority &priority,
  const string fmt, ...)
{
  // Variable to handle arguments.
  va_list arguments;
  // Initialize the argumet's list.
  va_start(arguments, fmt);
  // Pass to variadic function.
  this->printMessage(category, priority, fmt, arguments);
  // Deinitialize the argumet's list.
  va_end(arguments);
}

// Variadic function to print messages.
void Log::printMessage(const LogCategory &category, const LogPriority &priority,
  const string fmt, va_list arguments)
{
  // Pass to SDL_LogMessageV
  SDL_LogMessageV(static_cast<SDL_LogCategory>(category),
    static_cast<SDL_LogPriority>(priority), fmt.c_str(), arguments);
}

// Print a message with LogCategory::VERBOSE.
void Log::printVerbose(const LogCategory &category, const string fmt, ...)
{
  // Variable to handle arguments.
  va_list arguments;
  // Initialize the argument's list.
  va_start(arguments, fmt);
  // Pass to variadic function.
  this->printMessage(category, LogPriority::VERBOSE, fmt, arguments);
  // Deinitialize the argument's list.
  va_end(arguments);
}

// Print a string with LogPriority::VERBOSE priority.
void Log::printVerboseString(
  const LogCategory &category, const std::string &str)
{
  this->printVerbose(category, "%s", str.c_str());
}

// Print a string followed by a newline with LogPriority::VERBOSE priority.
void Log::printVerboseLine(const LogCategory &category, const string &str)
{
  this->printVerbose(category, "%s\n", str.c_str());
}

// Print a message with LogCategory::WARN.
void Log::printWarn(const LogCategory &category, const string fmt, ...)
{
  // Variable to handle arguments.
  va_list arguments;
  // Initialize the argument's list.
  va_start(arguments, fmt);
  // Pass to variadic function.
  this->printMessage(category, LogPriority::WARN, fmt, arguments);
  // Deinitialize the argument's list.
  va_end(arguments);
}

// Print a string with LogPriority::WARN priority.
void Log::printWarnString(const LogCategory &category, const std::string &str)
{
  this->printWarn(category, "%s", str.c_str());
}

// Print a string followed by a newline with LogPriority::WARN priority.
void Log::printWarnLine(const LogCategory &category, const string &str)
{
  this->printWarn(category, "%s\n", str.c_str());
}

// Get the current log output function.
void Log::getOutputFunction(LogOutputFunction *callback, void **userdata)
{
  SDL_LogGetOutputFunction(callback, userdata);
}

// Replace the default log output finction with one of your own.
void Log::setOutputFunction(LogOutputFunction callback, void **userdata)
{
  SDL_LogSetOutputFunction(callback, userdata);
}

// Get the prioriyñty of a particular log category.
LogPriority Log::getPriority(const LogCategory &category)
{
  return static_cast<LogPriority>(
    SDL_LogGetPriority(static_cast<SDL_LogCategory>(category)));
}

// Set the priority for a particular log category.
void Log::setPriority(const LogCategory &category, const LogPriority &priority)
{
  SDL_LogSetPriority(static_cast<SDL_LogCategory>(category),
    static_cast<SDL_LogPriority>(priority));
}

// Set the priority of all log categories.
void Log::setAllPriority(const LogPriority &priority)
{
  SDL_LogSetAllPriority(static_cast<SDL_LogPriority>(priority));
}

// Get the unique instance of the class.
Log &Log::getInstace()
{
  static Log theLog;
  return theLog;
}
