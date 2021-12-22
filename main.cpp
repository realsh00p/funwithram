#include "Bar.hpp"
#include "Foo.hpp"

#include "ContiguousMonostate.hpp"
#include "StaticMonostate.hpp"

#include <memory>

int foo_data {1};
int bar_data {2};

void doStaticMonostate() {
    using Foo = std::unique_ptr<StaticMonostate<other::Foo>>;
    using Bar = std::unique_ptr<StaticMonostate<other::Bar>>;

    Foo foo;
    {
        foo = std::make_unique<StaticMonostate<other::Foo>>(foo_data);
        foo->get().doFoo();
    }

    Bar bar;
    {
        bar = std::make_unique<StaticMonostate<other::Bar>>(bar_data);
        bar->get().doBar();
    }
}

void doContiguousMonostate() {
    using Foo = std::unique_ptr<ContiguousMonostate<other::Foo, other::Foo, other::Bar>>;
    using Bar = std::unique_ptr<ContiguousMonostate<other::Bar, other::Foo, other::Bar>>;

    Foo foo;
    {
        foo = std::make_unique<Foo::element_type>(foo_data);
        foo->get().doFoo();
    }

    Bar bar;
    {
        bar = std::make_unique<Bar::element_type>(bar_data);
        bar->get().doBar();
    }
}

int main(void) {
    doStaticMonostate();
    doContiguousMonostate();

    std::cin.get();
}
