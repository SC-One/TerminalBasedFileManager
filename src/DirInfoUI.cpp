#include <tbfm/DirInfoUI.h>

//#include <ftxui/component/captured_mouse.hpp>
//#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>

DirInfoUI::DirInfoUI() : _uiUpdater([]() { return ftxui::vbox(); }) {
  using namespace ftxui;
  _buttons = Container::Horizontal({
      Button("Decrease", [&] {}),
      Button("Increase", [&] {}),
  });

  // Modify the way to render them on screen:
  _comp = Renderer(_buttons, [&] {
    return vbox({
               text("value = " + std::to_string(20)),
               separator(),
               gauge(20 * 0.01f),
               separator(),
               _buttons->Render(),
           }) |
           border;
  });
}

std::shared_ptr<ftxui::ComponentBase> DirInfoUI::comp() const { return _comp; }
