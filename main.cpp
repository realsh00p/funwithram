#include "Bar.hpp"
#include "Foo.hpp"
#include "StaticSingleton.hpp"

#include <memory>

int main(int argc, char *argv[]) {
    
    int foo_data {1};
    int bar_data {2};

    std::unique_ptr<StaticSingleton<Foo>> foo;
    std::unique_ptr<StaticSingleton<Bar>> bar;

    {
        foo = std::make_unique<StaticSingleton<Foo>>(foo_data);
        foo->get().doFoo();
    }
    {
        bar = std::make_unique<StaticSingleton<Bar>>(bar_data);
        bar->get().doBar();
    }

    std::cin.get();
}