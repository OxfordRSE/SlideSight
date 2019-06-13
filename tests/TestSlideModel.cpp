//
// Created by gralee on 11/06/19.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <QGuiApplication>
#include <QPoint>
#include <QSignalSpy>
#include <QPixmap>

#include "SlideModel.hpp"
#include "Slide.hpp"

const int64_t STUB_WIDTH = 640, STUB_HEIGHT = 480;

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
        return STUB_WIDTH;
    }

    int64_t height() override {
        return STUB_HEIGHT;
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

TEST_CASE("Provides a zero-sized image with no slide", "[SlideModel]")
{
    SlideModel model;
    QPoint imageSize = model.dimensions();
    REQUIRE(imageSize.x() == 0);
    REQUIRE(imageSize.y() == 0);
}

TEST_CASE(".dimensions() returns the size of the slide", "[SlideModel]")
{
    SlideModel model;
    StubSlide slide;
    model.setSlide(&slide);
    QPoint imageSize = model.dimensions();
    REQUIRE(imageSize.x() == STUB_WIDTH);
    REQUIRE(imageSize.y() == STUB_HEIGHT);
}

TEST_CASE(".imageAtPoint()", "[SlideModel]")
{
    SlideModel model;
    SECTION("the slide is empty so the image returned is null")
    {
        QPoint offset(10,10), size(100,100);
        QPixmap image = model.imageAtPoint(offset, size);
        REQUIRE(image.isNull());
    }

    StubSlide slide;
    model.setSlide(&slide);
    SECTION("the slide is not empty")
    {
        SECTION("the offset is out of bounds so the image returned is null")
        {
            QPoint offset(-1, -1), size(100, 100);
            QPixmap image = model.imageAtPoint(offset, size);
            REQUIRE(image.isNull());
        }

        SECTION("the image extent is out of bounds so the image returned is null")
        {
            QPoint offset(600, 400), size(100, 100);
            QPixmap image = model.imageAtPoint(offset, size);
            REQUIRE(image.isNull());
        }

        SECTION("the image is within the slide's bounds and is not null")
        {
             QPoint offset(10,10), size(100,100);
             QPixmap image = model.imageAtPoint(offset, size);
             REQUIRE(!image.isNull());
             REQUIRE(image.size() == QSize(size.x(), size.y()));
        }
    }
}

// We need to have a Qt app for QPixmap to work in the tests.
QGuiApplication *app;
__attribute__((constructor)) void __initialise_qt()
{
    const char *arg_list[] = {"/bin/false"};
    char **argv = const_cast<char **>(arg_list);
    int argc = 1;
    app = new QGuiApplication(argc, argv);
}