//
// Created by gralee on 11/06/19.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <QSignalSpy>

#include "SlideModel.hpp"
#include "Slide.hpp"

// Stub implementation of the Slide interface
class StubSlide : public sight::Slide
{
public:
    void open(const std::string &filename) override {
        Q_UNUSED(filename)
    }

    void close() override {

    }

    int64_t width() override {
        return 640;
    }

    int64_t height() override {
        return 480;
    }
};

TEST_CASE("Emits signal on slide change", "[SlideModel]")
{
    StubSlide slide;
    SlideModel model;
    QSignalSpy spy(&model, SIGNAL(slideChanged()));
    model.setSlide(&slide);
    REQUIRE(spy.count() == 1);
}