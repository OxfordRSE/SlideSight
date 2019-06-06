// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SightLib.hpp"

// This tests the output of the `get_nth_prime` function
TEST_CASE("correct magic numbers are returned", "[magic]") {
  CHECK(sight::magic_function(2) == 5);
  CHECK(sight::magic_function(3) == 8);
  CHECK(sight::magic_function(-5) == 23);
  CHECK(sight::magic_function(15) == 23);
}

TEST_CASE("testing filesystem", "[fs]") {

  std::string path = sight::file_magic();

  CHECK(path.size() > 5);
}
