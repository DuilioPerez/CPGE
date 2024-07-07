// File: Hints.cpp
// Author: DP-Dev
// Implementation of the class Hints.
#include "Hints.hpp"
using namespace CPGE;
using namespace std;

// Define the reference to the unique instance of the class HintsManager.
HintsManager &CPGE::theHintsManager = HintsManager::getInstace();

// Add a watcher function to a hint.
void HintsManager::addCallback(
  const string &name, SDL_HintCallback callback, void *userdata)
{
  SDL_AddHintCallback(name.c_str(), callback, userdata);
}

// Delete a watcher function of a hint.
void HintsManager::delCallback(
  const string &name, SDL_HintCallback callback, void *userdata)
{
  SDL_DelHintCallback(name.c_str(), callback, userdata);
}

// Get the value of a hint.
const string HintsManager::get(const string &name)
{
  const char *hintValue = SDL_GetHint(name.c_str());
  if (!hintValue)
    return "";
  return hintValue;
}

bool HintsManager::getBoolean(const string &name, bool defaultValue)
{
  return SDL_GetHintBoolean(name.c_str(), static_cast<SDL_bool>(defaultValue));
}

// Reset a hint.
bool HintsManager::reset(const string &name)
{
  return SDL_ResetHint(name.c_str());
}

// Reset all the hints.
void HintsManager::reset()
{
  SDL_ResetHints();
}

// Set a hint.
bool HintsManager::set(const string &name, const string &value)
{
  return SDL_SetHint(name.c_str(), value.c_str());
}

// Set a hint with a priority degree.
bool HintsManager::setWithPriority(
  const string &name, const string &value, HintPriority priority)
{
  return SDL_SetHintWithPriority(
    name.c_str(), value.c_str(), static_cast<SDL_HintPriority>(priority));
}

// Get the unique instance of the class HintsManager.
HintsManager &HintsManager::getInstace()
{
  static HintsManager theHintsManager;
  return theHintsManager;
}
