#pragma once

#include <array>
#include <cstddef>
#include <type_traits>

template <typename... Types>
struct TypeList {
    static constexpr std::size_t size() {
        // const std::array<std::size_t, sizeof...(Types)> sizes {sizeof(Types)...};
        // std::size_t ret {0};
        // for (auto s : sizes) {
        //     ret += s;
        // }

        std::size_t ret = 0;
        using I = std::size_t[];
        (void)(I {0u, ret += sizeof(Types)...});

        return ret;
    }
};
