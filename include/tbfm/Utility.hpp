#ifndef UTILITY_HPP
#define UTILITY_HPP
#include <string>

namespace Utility {
template <typename CONTAINER_ELEM>
bool isEqual(const CONTAINER_ELEM &first, const CONTAINER_ELEM &second) {
  if (first.size() != second.size()) return false;
  for (std::size_t i = 0; i < first.size(); ++i) {
    if (first[i] != second[i]) return false;
  }
  return true;
}
}  // namespace Utility

#endif  // UTILITY_HPP
