#include "SightLib.hpp"

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

} // namespace sight
