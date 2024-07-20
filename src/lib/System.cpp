// File: System.cpp
// Author: DP-Dev
// Implementation of a class to handle SDL.
#include <CPGE/System.hpp>
using namespace CPGE;

// Defines the instance of the class.
System &CPGE::theSystem = System::getInstance();

// Initialize SDL.
bool System::init(const Subsystem &subsystems)
{
  if (SDL_Init(static_cast<Uint32>(subsystems)) < 0)
    return false;
  return true;
}

// Initialize a subsystem.
bool System::initSubsystem(const Subsystem &subsystems)
{
  if (SDL_InitSubSystem(static_cast<Uint32>(subsystems)) < 0)
    return false;
  return true;
}

// Clean up all the initialized subsystems.
void System::quit()
{
  SDL_Quit();
}

// Shut down an especific SDL subsystem.
void System::quitSubsystem(const Subsystem &subsystems)
{
  SDL_QuitSubSystem(static_cast<Uint32>(subsystems));
}

// Circumvent failure of System::init() when no using SDL_main as your entry
// point.
void System::setMainReady()
{
  SDL_SetMainReady();
}

// Get a mask of all initialzed subsystems.
Uint32 System::wasInit(const Subsystem &subsystems)
{
  return SDL_WasInit(static_cast<Uint32>(subsystems));
}

// Get the unique instance of the class.
System &System::getInstance()
{
  static System SDLSystem;
  return SDLSystem;
}
