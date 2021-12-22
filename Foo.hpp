#pragma once

#include <iostream>

class Foo {
public:
    Foo() = delete;
    Foo(Foo&&) = delete;
    Foo& operator=(Foo&&) = delete;
    Foo& operator=(const Foo&) = delete;

    Foo(const int& _foo) : foo(_foo) {};

    void doFoo() {
        std::cerr << "doFoo(): " << foo << std::endl;
    }

private:
    const int& foo;
};