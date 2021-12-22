#pragma once

#include <array>
#include <cstddef>
#include <memory>
#include <mutex>

template <typename... Types>
class ContiguousMonostateAllocator {
public:
    static void *allocate(std::size_t size) {
        std::lock_guard<std::mutex> lock(mux);

        // using defer = std::shared_ptr<void>;
        // defer _(nullptr, [&size] (...) { idx += size; });
        // return storage.data() + idx;

        void *ret {storage.data() + idx};
        idx += size;
        return ret;
    }

private:
    static std::mutex mux;
    static std::size_t idx;
    static std::array<char, sizeof...(Types)> storage;
};

template <typename... Types>
std::mutex ContiguousMonostateAllocator<Types...>::mux {};

template <typename... Types>
std::size_t ContiguousMonostateAllocator<Types...>::idx {0};

template <typename... Types>
std::array<char, sizeof...(Types)> ContiguousMonostateAllocator<Types...>::storage {0};
