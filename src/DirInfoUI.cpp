#include <tbfm/DirInfoUI.h>

//#include <ftxui/component/captured_mouse.hpp>
//#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/dom/elements.hpp>
#include <tbfm/Utility.hpp>

using namespace ftxui;

static auto make_box_fake(int dimx, int dimy) {
  std::string title = std::to_string(dimx) + "x" + std::to_string(dimy);
  return window(text(title) | hcenter | bold, text("content") | hcenter | dim) |
         size(WIDTH, EQUAL, dimx) | size(HEIGHT, EQUAL, dimy);
}

static auto make_box(int dimx, int dimy) {
  std::string title = std::to_string(dimx) + "x" + std::to_string(dimy);
  return window(text(title) | hcenter | bold, text("content") | hcenter | dim) |
         size(WIDTH, EQUAL, dimx) | size(HEIGHT, EQUAL, dimy);
}

DirInfoUI::DirInfoUI() : _clicked(false) {
  using namespace ftxui;
  updateDirs();

  //  // Modify the way to render them on screen:
  _comp = CatchEvent(Renderer(_dirBtns,
                              [&]() {
                                repaint();
                                return gridbox({{_dirBtns->Render()}});
                              }),
                     [&](Event event) {
                       if (Event::Backspace == event) {
                         _dirInfo.cd("..");
                         _clicked = true;
                       } else if (Event::Tab == event) {
                         if (nullptr != _screen) {
                           _screen->Exit();
                           return true;
                         }
                       }
                       return false;
                     });
}

std::shared_ptr<ftxui::ComponentBase> DirInfoUI::comp() const { return _comp; }

void DirInfoUI::repaint() {
  if (_clicked) {
    updateDirs();
    _clicked = false;
    _comp->TakeFocus();
  }
}

std::string DirInfoUI::loop() {
  auto screen = ScreenInteractive::FitComponent();
  _screen = &screen;
  screen.Loop(_comp);
  return _dirInfo.currentDir();
}

static std::string nameOfLastExt(std::string const& fullPath) {
  auto ind = fullPath.find_last_of('/');
  if (std::string::npos == ind) return fullPath;
  if (ind == fullPath.size() - 1) {
    auto newPath = fullPath.substr(0, fullPath.size() - 1);
    return nameOfLastExt(newPath);
  }
  return fullPath.substr(ind + 1);
}

void DirInfoUI::updateDirs() {
  _dirBtns.reset();
  auto const names = _dirInfo.ls();
  Components dirs;
  for (auto const& dirInfo : names) {
    auto exactFileName = nameOfLastExt(dirInfo);
    dirs.push_back(
        std::move(ftxui::Button(exactFileName, [this, exactFileName] {
          _dirInfo.cd(exactFileName);
          _clicked = true;
        })));
  }
  _dirBtns = ftxui::Container::Horizontal(dirs);
}
