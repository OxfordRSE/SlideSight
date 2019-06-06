#include "SightLib.hpp"

#include <filesystem>

#include <iostream>

namespace sight {

int magic_function(int n) {

  switch (n) {
  case 2:
    return 5;
  case 3:
    return 8;
  default:
    return 23;
  }
}

std::string file_magic() {

  return std::filesystem::absolute(std::filesystem::path{"."}).string();

}

} // namespace sight
