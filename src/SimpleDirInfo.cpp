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

std::string SimpleDirInfo::currentDir() const { return _path; }

bool SimpleDirInfo::cd(const std::string &entry) try {
  if (entry == "..") {
    _path = _path.parent_path();
    return true;
  } else {
    auto tmp = _path / entry;
    if (!tmp.empty()) {
      if (fs::is_directory(tmp)) {
        _path = tmp;
        return true;
      }
    }
  }
  return false;
} catch (...) {
  return false;
}

bool SimpleDirInfo::mkdir(const std::string &nextPath) {
  //  auto tmp = fs::path(nextPath);
  //  if (tmp.is_relative())
  //    ;
  return fs::create_directory(_path / nextPath);
}

std::vector<std::string> SimpleDirInfo::ls(const std::string &path) {
  SimpleDirInfo tmp(path);
  return tmp.ls();
}
