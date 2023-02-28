#include <tbfm/SimpleDirInfo.h>

#include <type_traits>
namespace fs = std::filesystem;

// use / for paths
SimpleDirInfo::SimpleDirInfo(const std::string &pathDir) : _path(pathDir) {}
SimpleDirInfo::SimpleDirInfo() : SimpleDirInfo(WhereExecuted) {}

std::vector<std::string> SimpleDirInfo::ls() const {
  std::vector<std::string> result;
  for (auto const &entry : fs::directory_iterator(_path))
    result.push_back(entry.path());
  return result;
}

std::vector<std::string> SimpleDirInfo::ls(const std::string &path) {
  SimpleDirInfo tmp(path);
  return tmp.ls();
}
