#include "screenmanager.h"

ScreenManager &ScreenManager::get_instance() {
  static ScreenManager instance;
  return instance;
}

ScreenManager::ScreenManager() {}

ScreenManager::~ScreenManager() {}
