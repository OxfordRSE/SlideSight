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

  private:
    data_t data;
};
}

#endif // SLIDEDATA_H
