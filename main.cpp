#include "Bar.hpp"
#include "Foo.hpp"
#include "StaticMonostate.hpp"

#include <memory>

int main(void) {
    
    int foo_data {1};
    int bar_data {2};

    std::unique_ptr<StaticMonostate<Foo>> foo;
    std::unique_ptr<StaticMonostate<Bar>> bar;

    {
        foo = std::make_unique<StaticMonostate<Foo>>(foo_data);
        foo->get().doFoo();
    }
    {
        bar = std::make_unique<StaticMonostate<Bar>>(bar_data);
        bar->get().doBar();
    }

    std::cin.get();
}