#ifndef SLIDEDATA_H
#define SLIDEDATA_H

#include <memory>
#include <string>
#include <openslide.h>
#include "Slide.hpp"

namespace sight {

class SlideData : public Slide {
  using data_t = std::unique_ptr<openslide_t, decltype(&openslide_close)>;

  public:
    SlideData();
    void open(const std::string& filename) override;
    void close() override;
    int64_t width() override;
    int64_t height() override;
  private:
    data_t data;
    int64_t w=-1, h=-1;
};
}

#endif // SLIDEDATA_H
