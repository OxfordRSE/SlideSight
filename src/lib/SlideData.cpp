#include "SlideData.hpp"

#include "Filesystem.hpp"
#include <iostream>

namespace sight {

SlideData::SlideData()
    : data(nullptr, openslide_close)
{
}

void SlideData::open(const std::string& filename)
{

  if (!SIGHT_FILESYSTEM_NS::exists(filename)) {
    throw std::runtime_error("Could not find file: " + filename);
  }
  const char* vendor_name_raw = openslide_detect_vendor(filename.c_str());
  if (!vendor_name_raw) {
    throw std::runtime_error("Could not detect filetype vendor for " + filename);
  }
  std::string vendor_name(vendor_name_raw);
  data = data_t(openslide_open(filename.c_str()), openslide_close);
  if (!data) {
    throw std::runtime_error(
        "Error reading slide file " + filename + "with vendor " + vendor_name);
  }

  std::cout << "Opened filename \"" << filename <<"\":"<< std::endl;
  std::cout << "\t- vendor " << vendor_name << std::endl;

  const int level_count = openslide_get_level_count(data.get());
  std::cout << "\t- level count " << level_count << std::endl;

  openslide_get_level0_dimensions(data.get(), &w, &h);

  std::cout << "\t- level 0 dimensions (" << w << 'x' << h << ")"
            << std::endl;
}
void SlideData::close()
{
  if (!data) {
    openslide_close(data.get());
  }
}
int64_t SlideData::height() { return h; }
int64_t SlideData::width() { return w; }
}
