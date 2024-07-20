/// @file Log.hpp
/// @author DP-Dev
/// @brief A class to write data to the platform defined stream.
#ifndef LOG_HPP
#define LOG_HPP true
#include <SDL2/SDL.h>
#include <cstdarg>
#include <string>

namespace CPGE
{
  /// @brief The category to log a message.
  ///
  /// By default the application category is enabled at the INFO level, the
  /// assert category is enabled at the WARN level, test is enabled at the
  /// VERBOSE level and all other categories are enabled at the ERROR level.
  enum struct LogCategory
  {
    /// @brief Log information about the application.
    APPLICATION = SDL_LOG_CATEGORY_APPLICATION,
    /// @brief Log information about an error.
    ERROR = SDL_LOG_CATEGORY_ERROR,
    /// @brief Assertion information.
    ASSERT = SDL_LOG_CATEGORY_ASSERT,
    /// @brief System information.
    SYSTEM = SDL_LOG_CATEGORY_SYSTEM,
    /// @brief Log information about the audio system.
    AUDIO = SDL_LOG_CATEGORY_AUDIO,
    /// @brief Information about the video subsystem.
    VIDEO = SDL_LOG_CATEGORY_VIDEO,
    /// @brief Information about the rendering process.
    RENDER = SDL_LOG_CATEGORY_RENDER,
    /// @brief Information about the input devices.
    INPUT = SDL_LOG_CATEGORY_INPUT,
    /// @brief Information about tests.
    TEST = SDL_LOG_CATEGORY_TEST
  };

  /// @brief The priority of the messages.
  enum struct LogPriority
  {
    /// @brief Verbose message.
    VERBOSE = SDL_LOG_PRIORITY_VERBOSE,
    /// @brief Debug message.
    DEBUG = SDL_LOG_PRIORITY_DEBUG,
    /// @brief Informatibe message.
    INFO = SDL_LOG_PRIORITY_INFO,
    /// @brief Warning message.
    WARN = SDL_LOG_PRIORITY_WARN,
    /// @brief Error message.
    ERROR = SDL_LOG_PRIORITY_ERROR,
    /// @brief Critical error message.
    CRITICAL = SDL_LOG_PRIORITY_CRITICAL
  };

  /// @brief The log output function's type.
  typedef SDL_LogOutputFunction LogOutputFunction;

  /// @brief A class to write data to the platform defined stream.
  class Log final
  {
  public:
    /// @brief Copy constructor deleted.
    Log(const Log &) = delete;
    /// @brief Print a message with LogCategory::APPLICATION and
    /// LogPriority::INFO.
    /// @param fmt a printf() style message format string.
    /// @param ... additional parameters matching % tokens in the fmt string, if
    /// any.
    /// @sa Log::printString()
    /// @sa Log::printLine()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void print(const std::string fmt, ...);
    /// @brief Print a string message with LogCategory::APPLICATION and
    /// LogPriority::INFO.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printLine()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printString(const std::string &str);
    /// @brief Print a string followed by a newline character with
    /// LogCategory::APPLICATION and LogPriority::INFO.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printString()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printLine(const std::string &str);
    /// @brief Print a message with LogPriority::CRITICAL.
    /// @param category The category of the message.
    /// @param fmt A printf style message format.
    /// ... additional parameters matching % tokens in the fmt string, if any.
    /// @sa Log::print()
    /// @sa Log::printCriticalString()
    /// @sa Log::printCriticalLine()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printCritical(const LogCategory &category, const std::string fmt, ...);
    /// @brief Print a string message with LogPriority::CRITICAL.
    /// @param category The category of the message.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printCriticalLine()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printCriticalString(
      const LogCategory &category, const std::string &str);
    /// @brief Print a string followed by a newline character with
    /// LogPriority::CRITICAL.
    /// @param category The category of the message.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printCriticalString()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printCriticalLine(const LogCategory &category, const std::string &str);
    /// @brief Print a message with LogPriority::DEBUG.
    /// @param category The category of the message.
    /// @param fmt A printf style message format.
    /// ... additional parameters matching % tokens in the fmt string, if any.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebugString()
    /// @sa Log::printDebugLine()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printDebug(const LogCategory &category, const std::string str, ...);
    /// @brief Print a string message with LogPriority::DEBUG.
    /// @param category The category of the message.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printDebugLine()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printDebugString(const LogCategory &category, const std::string &str);
    /// @brief Print a string followed by a newline character with
    /// LogPriority::DEBUG.
    /// @param category The category of the message.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printDebugLine()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printDebugLine(const LogCategory &category, const std::string &str);
    /// @brief Print a message with LogPriority::ERROR.
    /// @param category The category of the message.
    /// @param fmt A printf style message format.
    /// ... additional parameters matching % tokens in the fmt string, if any.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printErrorString()
    /// @sa Log::printErrorLine()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printError(const LogCategory &category, const std::string str, ...);
    /// @brief Print a string message with LogPriority::ERROR.
    /// @param category The category of the message.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printErrorLine()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printErrorString(const LogCategory &category, const std::string &str);
    /// @brief Print a string followed by a newline character with
    /// LogPriority::ERROR.
    /// @param category The category of the message.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printErrorLine()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printErrorLine(const LogCategory &category, const std::string &str);
    /// @brief Print a message with LogPriority::INFO.
    /// @param category The category of the message.
    /// @param fmt A printf style message format.
    /// ... additional parameters matching % tokens in the fmt string, if any.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfoString()
    /// @sa Log::printInfoLine()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printInfo(const LogCategory &category, const std::string str, ...);
    /// @brief Print a string message with LogPriority::INFO.
    /// @param category The category of the message.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printInfoLine()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printInfoString(const LogCategory &category, const std::string &str);
    /// @brief Print a string followed by a newline character with
    /// LogPriority::INFO.
    /// @param category The category of the message.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printInfoString()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printInfoLine(const LogCategory &category, const std::string &str);
    /// @brief Print a message with the specified category and priority.
    /// @param priority The priority of the message.
    /// @param category The category of the message.
    /// @param fmt A printf style message format string.
    /// @param ... Additional parameters matching % tokens in the fmt string, if
    /// any.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printInfo()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printMessage(const LogCategory &category, const LogPriority &priority,
      const std::string fmt, ...);
    /// @brief Print a message with the specified category and priority.
    /// @param priority The priority of the message.
    /// @param category The category of the message.
    /// @param fmt A printf style message format string.
    /// @param list A variable agument list.
    /// any.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printInfo()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printMessage(const LogCategory &category, const LogPriority &priority,
      const std::string fmt, va_list list);
    /// @brief Print a message with LogPriority::VERBOSE.
    /// @param category The category of the message.
    /// @param fmt A printf style message format.
    /// ... additional parameters matching % tokens in the fmt string, if any.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerboseString()
    /// @sa Log::printVerboseLine()
    /// @sa Log::printWarn()
    void printVerbose(const LogCategory &category, const std::string str, ...);
    /// @brief Print a string message with LogPriority::VERBOSE.
    /// @param category The category of the message.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printVerboseLine()
    /// @sa Log::printWarn()
    void printVerboseString(
      const LogCategory &category, const std::string &str);
    /// @brief Print a string followed by a newline character with
    /// LogPriority::VERBOSE.
    /// @param category The category of the message.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printVerboseString()
    /// @sa Log::printWarn()
    void printVerboseLine(const LogCategory &category, const std::string &str);
    /// @brief Print a message with LogPriority::WARN.
    /// @param category The category of the message.
    /// @param fmt A printf style message format.
    /// ... additional parameters matching % tokens in the fmt string, if any.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarnString()
    /// @sa Log::printWarnLine()
    void printWarn(const LogCategory &category, const std::string str, ...);
    /// @brief Print a string message with LogPriority::WARN.
    /// @param category The category of the message.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    /// @sa Log::printWarnLine()
    void printWarnString(const LogCategory &category, const std::string &str);
    /// @brief Print a string followed by a newline character with
    /// LogPriority::WARN.
    /// @param category The category of the message.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printInfo()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    /// @sa Log::printWarnString()
    void printWarnLine(const LogCategory &category, const std::string &str);
    /// @brief Get the current log output function.
    /// @param callback A pointer to fill with the current log callback.
    /// @param userdata A pointer to be filled with the pointer that is passed
    /// to callback.
    /// @sa Log::setOutputFunction()
    void getOutputFunction(LogOutputFunction *callback, void **userdata);
    /// @brief Replace the default log output function with one of your own.
    /// @param callback A function to call instead of the default.
    /// @param userdata A pointer that is passed to callback.
    /// @sa Log::getOutputFunction()
    void setOutputFunction(LogOutputFunction callback, void **userdata);
    /// @brief Get the priority of a particular log category.
    /// @param category The category to query.
    /// @return The SDL_LogPriority for the requested category.
    /// @sa Log::setPriority()
    LogPriority getPriority(const LogCategory &category);
    /// @brief Set the priority for a particular log category.
    /// @param category The category to assign a priority to.
    /// @param priority The LogPriority to assign.
    /// @sa Log::getPriority()
    /// @sa Log::setAllPriority()
    void setPriority(const LogCategory &category, const LogPriority &priority);
    /// @brief Set the priority of all log categories.
    /// @param priority The SDL_LogPriority to assign.
    /// @sa Log::setPriority()
    void setAllPriority(const LogPriority &priority);
    /// @brief Copy operator deleted.
    const Log &operator=(const Log &);
    /// @brief Get the unique instance of the class.
    static Log &getInstace();

  private:
    /// @brief Private default constructor.
    Log() = default;
  };
} // namespace CPGE
#endif
