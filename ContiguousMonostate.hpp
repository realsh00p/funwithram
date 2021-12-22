#pragma once

#include "ContiguousMonostateAllocator.hpp"

template <typename T, typename... Types>
class ContiguousMonostate {
public:
    template <typename... Args>
    ContiguousMonostate(Args &&...args) : instance(std::forward<Args>(args)...) {
    }

    T &get() {
        return instance;
    };

    void *operator new(std::size_t size) {
        (void)size;
        return ContiguousMonostateAllocator<Types...>::allocate(size);
    }

    void operator delete(void *addr) {
        (void)addr;
        // nop
    }

private:
    T instance;
};
