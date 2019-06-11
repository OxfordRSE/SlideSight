//
// Created by gralee on 11/06/19.
//

#ifndef SLIDESIGHT_SLIDE_HPP
#define SLIDESIGHT_SLIDE_HPP

namespace sight {
    class Slide {
    public:
        virtual void open(const std::string& filename);
        virtual void close();
        virtual int64_t width();
        virtual int64_t height();
    };
}

#endif //SLIDESIGHT_SLIDE_HPP
