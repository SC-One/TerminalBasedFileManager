#ifndef DIRINFOUI_H
#define DIRINFOUI_H

#include <tbfm/SimpleDirInfo.h>

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/elements.hpp>

class DirInfoUI {
 public:
  DirInfoUI();

  std::shared_ptr<ftxui::ComponentBase> comp() const;

 private:
  ftxui::Component _buttons;
  std::shared_ptr<ftxui::ComponentBase> _comp;
  std::function<ftxui::Element(void)> _uiUpdater;
  SimpleDirInfo _dirInfo;
};

#endif  // DIRINFOUI_H
