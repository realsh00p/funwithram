#pragma once

#include <array>
#include <cstddef>
#include <memory>
#include <mutex>

template <std::size_t Total>
class ContiguousMonostateAllocator {
private:
    using defer = std::shared_ptr<void>;

public:
    static void *allocate(std::size_t size) {
        static std::mutex mux {};
        static std::size_t idx {0};
        static std::array<char, Total> storage {0};

        std::lock_guard<std::mutex> lock(mux);

        if (idx + size > Total) {
            throw std::bad_alloc();
        }

        defer _(nullptr, [&size](...) { idx += size; });
        return storage.data() + idx;
    }
};
