#include <tbfm/DirInfoUI.h>

#include <cstdlib>
#include <iostream>
#include <string>

void cls() {
  system("cls||clear");
  return;
}

int main(int argc, const char* argv[]) {
  using namespace ftxui;
  DirInfoUI dirInfos;
  auto result = dirInfos.loop();

  { cls(); }
  std::cout << result;
  return 0;
}
