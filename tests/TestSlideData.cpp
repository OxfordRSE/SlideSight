#include "catch.hpp"

#include "SightLib.hpp"

TEST_CASE("file not exists", "[SlideData]") {
  sight::SlideData data;
  data.open("does_not_exist");
}

TEST_CASE("file invalid format", "[SlideData]") {
  sight::SlideData data;
  data.open("../CMakeLists.txt");
}

TEST_CASE("open test file", "[SlideData]") {
  sight::SlideData data;
  data.open("CMU-1.ndpi");
}
