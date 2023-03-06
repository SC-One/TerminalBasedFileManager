#ifndef DIRINFOUI_H
#define DIRINFOUI_H

#include <tbfm/SimpleDirInfo.h>

#include <atomic>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>  // for ScreenInteractive
#include <ftxui/dom/elements.hpp>

class DirInfoUI {
 public:
  DirInfoUI();

  std::shared_ptr<ftxui::ComponentBase> comp() const;

  std::string loop();

 private:
  void repaint();
  void updateDirs();

 private:
  ftxui::Component _dirBtns;
  std::shared_ptr<ftxui::ComponentBase> _comp;
  SimpleDirInfo _dirInfo;
  std::atomic_bool _clicked;
  ftxui::ScreenInteractive* _screen;
};

#endif  // DIRINFOUI_H
