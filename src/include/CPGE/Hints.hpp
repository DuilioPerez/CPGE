/// @file Hints.hpp
/// @author DP-Dev
/// @brief Class to handle environment variables.
#ifndef HINTS_HPP
#define HINTS_HPP true
#include <SDL2/SDL.h>
#include <string>

namespace CPGE
{

  /// @brief An enumeration of hint priorities.
  enum struct HintPriority
  {
    /// @brief Default priority
    DEFAULT = SDL_HINT_DEFAULT,
    /// @brief Normal priority.
    NORMAL = SDL_HINT_NORMAL,
    /// @brief Overrde priority.
    OVERRIDE = SDL_HINT_OVERRIDE
  };

  /// @brief A class to handle environment variables.
  class HintsManager final
  {
  public:
    /// @brief Copy constructor deleted.
    HintsManager(const HintsManager &) = delete;
    /// @brief Add a function to watch a particular hint.
    /// @param name The hint to watch.
    /// @param callback A function to call when the hint value changes.
    /// @param userdata A pointer to pass to the callback function.
    /// @sa HintsManager::delCallback()
    void addCallback(const std::string &name, SDL_HintCallback callback,
      void *userdata = nullptr);
    /// @brief Remove a function watching a particular hint.
    /// @param name The hint being watching.
    /// @param callback A function to call when the hint value changes.
    /// @param userdata A pointer being passed to the callback function.
    /// @sa HintsManager::addCallback()
    void delCallback(const std::string &name, SDL_HintCallback callback,
      void *userdata = nullptr);
    /// @brief Get the value of a hint.
    /// @param name The name of the hint to query.
    /// @return The string value of the hint, or an empty string if isn't set.
    /// @sa HintsManager::set()
    /// @sa HintsManager::setWithPriority()
    const std::string get(const std::string &name);
    /// @brief Get the boolean value of a hint.
    /// @param name The name of the hint to query.
    /// @param defaultValue The value to return if the hint doesn't exist.
    /// @return The boolean value of a hint or the provided default value if the
    /// hint doesn't exist.
    /// @sa HintsManager::get()
    /// @sa HintsManager::set()
    bool getBoolean(const std::string &name, bool defaultValue);
    /// @brief Reset a hint to the degault value.
    /// @param name The mame of the hint to reset.
    /// @return true if the hint was set, false if not.
    ///
    /// This will reset a hint to the value of the environment variable, or
    /// nullptr if the environment isn't set. Callbacks will be called normally
    /// with this change.
    ///
    /// @sa HintsManager::get()
    /// @sa HintsManager::set()
    bool reset(const std::string &name);
    /// @brief Reset all hints to the default values.
    ///
    /// This will reset all hints to the value of the associated environment
    /// variable, or nullptr if the environment isn't set. Callbacks will be
    /// called normally with this change.
    void reset();
    /// @brief Set a hint with normal priority.
    /// @param name The hint to set.
    /// @param value The value of the hint variable.
    /// @return true if the hint was set, false otherwise.
    ///
    /// Hints will not be set if there is an existing override hint or
    /// environment variable that takes precedence. You can
    /// use HintsManager::setWithPriority() to set the hint with override
    /// priority instead.
    ///
    /// @sa HintsManager::get()
    /// @sa HintsManager::setWithPriority()
    bool set(const std::string &name, const std::string &value);
    /// @brief Set a hint with a specefic priority.
    /// @param name The hint to set.
    /// @param value The value of the hint variable.
    /// @param priority The priority level.
    /// @return true if the hint was set, false otherwise.
    ///
    /// The priority controls the behavior when setting a hint that already has
    /// a value. Hints will replace existing hints of their priority and lower.
    /// Environment variables are considered to have override priority.
    bool setWithPriority(const std::string &name, const std::string &value,
      HintPriority priority = HintPriority::OVERRIDE);
    /// @brief Copy operator deleted.
    const HintsManager &operator=(const HintsManager &) = delete;
    /// @brief Get the unique instance of the class.
    static HintsManager &getInstace();

  private:
    /// @brief Default constructor.
    HintsManager() = default;
  };

  /// @brief A reference to the uniqje instance of the class HintsManager.
  extern HintsManager &theHintsManager;

} // namespace CPGE

#endif
