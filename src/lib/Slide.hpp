//
// Created by gralee on 11/06/19.
//

#ifndef SLIDESIGHT_SLIDE_HPP
#define SLIDESIGHT_SLIDE_HPP

namespace sight {
    class Slide {
    public:
        virtual void open(const std::string& filename) = 0;
        virtual void close() = 0;
        virtual int64_t width() = 0;
        virtual int64_t height() = 0;
    };
}

#endif //SLIDESIGHT_SLIDE_HPP
