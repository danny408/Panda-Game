#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <iostream>
#include <string>

class ScreenManager {
 public:
  ~ScreenManager();
  static ScreenManager &get_instance();

 private:
  ScreenManager();
  ScreenManager(ScreenManager const &);
  void operator=(ScreenManager const &);
};

#endif  // SCREENMANAGER_H
