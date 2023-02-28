#ifndef SIMPLEDIRINFO_H
#define SIMPLEDIRINFO_H
#include <filesystem>
#include <string>
#include <vector>

class SimpleDirInfo {
  inline static const std::filesystem::path WhereExecuted =
      std::filesystem::current_path();

 public:
  explicit SimpleDirInfo(std::string const &pathDir);
  SimpleDirInfo();

  std::vector<std::string> ls() const;

 public:
  static std::vector<std::string> ls(std::string const &path);

 private:
  std::filesystem::path _path;
};

#endif  // SIMPLEDIRINFO_H
