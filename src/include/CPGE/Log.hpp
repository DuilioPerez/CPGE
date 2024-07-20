/// @file Log.hpp
/// @author DP-Dev
/// @brief A class to write data to the platform defined stream.
#ifndef LOG_HPP
#define LOG_HPP true
#include <SDL2/SDL.h>
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
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void print(const std::string fmt, ...);
    /// @brief Print a string message with LogCategory::APPLICATION and
    /// LogPriority::INFO.
    /// @param str The string to print.
    void printString(const std::string &str);
    /// @brief Print a string followed by a newline character with
    /// LogCategory::APPLICATION and LogPriority::INFO.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printLine()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printLine(const std::string &str);
    /// @brief Print a message with LogPriority::CRITICAL.
    /// @param category The category of the message.
    /// @param fmt A printf style message format.
    /// ... additional parameters matching % tokens in the fmt string, if any.
    /// @sa Log::print()
    /// @sa Log::printString()
    /// @sa Log::printCritical()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printCritical(const LogCategory &category, const std::string fmt, ...);
    /// @brief Print a string message with LogPriority::CRITICAL.
    /// @param category The category of the message.
    /// @param str The string to print.
    /// @sa Log::print()
    /// @sa Log::printCriticalString()
    /// @sa Log::printCriticalLine()
    /// @sa Log::printDebug()
    /// @sa Log::printError()
    /// @sa Log::printMessage()
    /// @sa Log::printVerbose()
    /// @sa Log::printWarn()
    void printCriticalString(
      const LogCategory &category, const std::string &str);
    /// @brief Print a string followed by a newline character with
    /// LogPriority::CRITICAL.
    /// @param category The category of the message.
    /// @param str The string to print.
    void printCriticalLine(const LogCategory &category, const std::string &str);
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
