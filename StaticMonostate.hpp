#pragma once

#include <array>
#include <cstddef>
#include <exception>
#include <mutex>
#include <new>
#include <utility>

template <typename T>
class StaticMonostate {
public:
    template <typename... Args>
    StaticMonostate(Args &&...args) : instance(std::forward<Args>(args)...) {
    }

    T &get() {
        return instance;
    }

    void *operator new(std::size_t size) {
        (void)size;
        std::lock_guard<std::mutex> lock(mux);
        if (allocated) {
            throw std::bad_alloc();
        }
        allocated = true;
        return storage.data();
    }

    void operator delete(void *p) {
        (void)p;
        std::lock_guard<std::mutex> lock(mux);
        allocated = false;
    }

private:
    T instance;

    static std::mutex mux;
    static bool allocated;
    static std::array<char, sizeof(T)> storage;
};

template <typename T>
std::mutex StaticMonostate<T>::mux {};

template <typename T>
bool StaticMonostate<T>::allocated {false};

template <typename T>
std::array<char, sizeof(T)> StaticMonostate<T>::storage {0};
