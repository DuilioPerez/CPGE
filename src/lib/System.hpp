/// @file System.hpp
/// @author DP-Dev
/// @brief Interface of a class to work with the SDL system.
#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include <SDL2/SDL.h>

/// @brief Namespace of the game engine.
///
/// This namespace provides all the classes and functions required to make a
/// basic game reducing the development time. At the same time, it is
/// multiplatform allowing compilation to Windows, MacOs, Linux, Android, IOS,
/// Emscripten and others.
namespace CPGE
{
  /// @brief SDL initialization flags.
  /// @sa System::init()
  /// @sa System::initSubsystem()
  /// @sa System::quitSubsystem()
  enum struct Subsystem
  {
    /// @brief None subsystem.
    NONE = 0,
    /// @brief Timer subsystem.
    TIMER = SDL_INIT_TIMER,
    /// @brief Audio Subsystem.
    AUDIO = SDL_INIT_AUDIO,
    /// @brief Video subsystem; automatically initializes the events subsystem.
    VIDEO = SDL_INIT_VIDEO,
    /// @brief Joystick subsystem; automatically initializes the events
    /// subsystem.
    JOYSTICK = SDL_INIT_JOYSTICK,
    /// @brief Haptic (force feedback) subsystem.
    HAPTIC = SDL_INIT_HAPTIC,
    /// @brief Controller subsystem; automatically initializes the joystick
    /// subsystem.
    GAMECONTROLLER = SDL_INIT_GAMECONTROLLER,
    /// @brief Events subsystem.
    EVENTS = SDL_INIT_EVENTS,
    /// @brief All the above subsystems.
    EVERYTHING = SDL_INIT_EVERYTHING
  };
  /// @brief A class to handle the SDL system.
  class System final
  {
  public:
    /// @brief Deleted copy constructor.
    System(const System &) = delete;
    /// @brief Initialize the SDL library.
    /// @param subsystems The subsystems to initialize.
    /// @return true in success, false in error. Call System::getError for more
    /// information.
    ///
    /// System::init() simply forwards to calling System::initSubSystem().
    /// Therefore, the two may be used interchangeably. Though for readability
    /// of your code System::initSubSystem() might be preferred.
    ///
    /// The file I/O (for example: Stream::RWFromFile()) and threading
    /// (Thread::create()) subsystems are initialized by default. Message boxes
    /// (MessageBox::ShowSimpleMessageBox()) also attempt to work without
    /// initializing the video subsystem, in hopes of being useful in showing an
    /// error dialog when System::init() fails. You must specifically initialize
    /// other subsystems if you use them in your application. Logging (such
    /// as Log::print()) works without initialization, too.
    ///
    /// flags may be any of the following OR'd together:
    /// Subsystem::TIMER: timer subsystem.
    /// Subsystem::AUDIO: audio subsystem.
    /// Subsystem::VIDEO: video subsystem; automatically initializes the
    /// events subsystem.
    /// Subsystem::JOYSTICK: joystick subsystem; automatically initializes
    /// the events subsystem.
    /// Subsystem::HAPTIC: haptic (force feedback) subsystem.
    /// Subsystem::GAMECONTROLLER: controller subsystem; automatically
    /// initializes the joystick subsystem. CPGE::Subsystem::EVENTS: events
    /// subsystem.
    /// Subsystem::EVERYTHING: all of the above subsystems.
    ///
    /// Subsystem initialization is ref-counted, you must
    /// call System::quitSubSystem() for
    /// each System::initSubSystem() to correctly shutdown a subsystem
    /// manually (or call System::quit() to force shutdown). If a
    /// subsystem is already loaded then this call will increase the ref-count
    /// and return.
    ///
    /// @sa Subsystem
    /// @sa System::initSubsystem()
    /// @sa System::quit()
    /// @sa System::setMainReady()
    /// @sa System::wasInit()
    bool init(const Subsystem &subsystems);
    /// @brief Compatibility function to initialize the SDL library.
    /// @param subsystems The subsystems to initialize.
    /// @return true in success, false otherwise. Call System::getError() for
    /// more information.
    ///
    /// This function is interchangeable with System::init().
    ///
    /// @sa Subsystem
    /// @sa System::init()
    /// @sa System::quit()
    /// @sa System::quitSubsystem()
    bool initSubsystem(const Subsystem &subsystems);
    /// @brief Clean up all initialized subsystems.
    ///
    /// You should call this function even if you have already shutdown each
    /// initialized subsystem with System::quitSubSystem(). It is safe to call
    /// this function even in the case of errors in initialization.
    ///
    /// If you start a subsystem using a call to that subsystem's init function
    /// (for example Video::init()) instead of System::init()
    /// or System::initSubSystem(), then you must use that subsystem's quit
    /// function (Video::quit()) to shut it down before calling System::quit().
    /// But generally, you should not be using those functions directly anyhow;
    /// use System::init() instead.
    ///
    /// You can use this function with atexit() to ensure that it is run when
    /// your application is shutdown, but it is not wise to do this from a
    /// library or other dynamically loaded code.
    ///
    /// @sa System::init()
    /// @sa System::quitSubsystem()
    void quit();
    /// @brief Shut down specifics SDL subsystems.
    /// @param subsystems The subsystems to shut down.
    ///
    /// If you start a subsystem using a call to that subsystem's init function
    /// (for example Video::init()) instead of System::init()
    /// or System::initSubSystem(), System::quitSubSystem()
    /// and System::wasInit() will not work. You will need to use that
    /// subsystem's quit function (Video::quit()) directly instead. But
    /// generally, you should not be using those functions directly anyhow;
    /// use System::init() instead.
    ///
    /// You still need to call System::quit() even if you close all open
    /// subsystems with System::quitSubSystem().
    ///
    /// @sa System::init()
    /// @sa System::quit()
    void quitSubsystem(const Subsystem &subsystems);
    /// @brief Circumvent failure of System::init() when no using SDL_main as
    /// your entry point.
    ///
    /// This function is defined along with the preprocessor rule to redefine
    /// main() as SDL_main(). Thus to ensure that your main() function will not
    /// be changed it is necessary to define Hint::MAIN_HANDLED before including
    /// System.hpp.
    ///
    /// @sa System::init()
    void setMainReady();
    /// @brief Get a mask of the specified subsystems wich are currently
    /// initialized.
    /// @param subsystems Any subsystem used by System::init(). See
    /// System::init() for more information.
    /// @return A mask of all initialized subsystems if subsystems is
    /// Subsystem::NONE. Otherwise it returns the initialozation status of the
    /// specified subsystems
    ///
    /// @sa Subsystem
    /// @sa System::init()
    /// @sa System::initSubsystem()
    Uint32 wasInit(const Subsystem &subsystems = Subsystem::NONE);
    /// @brief Get the unique instance of the class.
    static System &getInstance();

  private:
    /// @brief Private default constructor.
    System() = default;
  };

  /// @brief Instance of the class.
  extern System &theSystem;
} // namespace CPGE

#endif
