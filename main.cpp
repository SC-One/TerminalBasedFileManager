#include <stdio.h>
#include <tbfm/DirInfoUI.h>

#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>  // for ScreenInteractive
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
#include <string>

int main(int argc, const char* argv[]) {
  using namespace ftxui;
  DirInfoUI dirInfos;
  auto result = dirInfos.loop();
  std::cout << result;
  return 0;
}
