#include "catch.hpp"
using namespace Catch;

#include "SightLib.hpp"

TEST_CASE("file not exists", "[SlideData]")
{
  sight::SlideData data;
  REQUIRE_THROWS_WITH(data.open("does_not_exist"), Contains("Could not find file"));
}

TEST_CASE("file invalid format", "[SlideData]")
{
  sight::SlideData data;
  REQUIRE_THROWS_WITH(
      data.open("../CMakeLists.txt"), Contains("Could not detect filetype vendor"));
}

TEST_CASE("open test file", "[SlideData]")
{
  // TODO: don't want to include this 200MB file in the repo....
  //sight::SlideData data;
  //data.open("CMU-1.ndpi");
  //data.close();
}

