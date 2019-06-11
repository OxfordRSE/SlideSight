#ifndef SLIDEDATA_H
#define SLIDEDATA_H

#include <memory>
#include <string>
#include <openslide.h>

namespace sight {

class SlideData {
  using data_t = std::unique_ptr<openslide_t, decltype(&openslide_close)>;

  public:
    SlideData();
    void open(const std::string& filename);
    void close();
    int64_t width();
    int64_t height();
  private:
    data_t data;
    int64_t w=-1, h=-1;
};
}

#endif // SLIDEDATA_H
