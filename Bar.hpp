#pragma once

#include <iostream>

namespace other {

class Bar {
public:
    Bar() = delete;
    Bar(Bar &&) = delete;
    Bar &operator=(Bar &&) = delete;
    Bar &operator=(const Bar &) = delete;

    Bar(const int &_bar) : bar(_bar) {};

    void doBar() {
        std::cerr << "doBar(): " << bar << std::endl;
    }

private:
    const int &bar;
};

} // namespace other
