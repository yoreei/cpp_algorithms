#pragma once
#include<iostream>
#include<array>

namespace base_destructors_public_and_virtual_OR_protected_and_nonvirtual{}

namespace member_function_hiding {
    struct Base
    {
    private:
        void foo(float);
    };

    struct Derived: public Base
    {
    public:
        void foo(int); // hides foo(float) in Base
    };

    int main()
    {
        Derived d;
        //d.foo(5.0f); // error
        return 0;
    }
}

namespace keyword_override_is_optional {
    struct Base
    {
        virtual void foo() { std::cout<< "Base::foo\n"; }
    };

    struct Derived: public Base
    {
        void foo() { std::cout << "Derived::foo\n"; } // actually overrides Base:foo.
    };
    void main(){
        Derived d;
        Base& b = d;
        b.foo(); // prints "Derived::foo"
    }
}

namespace DO_NOT_default_parameters_in_virtual_functions {
    // Static Binding of Default Parameters
    class Base {
    public:
        virtual void foo(int a = 10) {
            std::cout << "Base::foo with a = " << a << std::endl;
        }
    };

    class Derived : public Base {
    public:
        void foo(int a = 20) override {
            std::cout << "Derived::foo with a = " << a << std::endl;
        }
    };

    void main() {
        Derived d;
        Base* bp = &d;
        bp->foo(); // Calls Derived::foo but uses Base's default parameter value (10)
    }
}

namespace nvi_and_Template_Method {
    class Gadget
    {
    };
    class Widget
    {
    public:
      // Stable, nonvirtual interface.
      //
      int Process( Gadget& ); // uses DoProcess...()
      bool IsDone(); // uses DoIsDone()
      // ...

    private:
      // Customization is an implementation detail that may
      // or may not directly correspond to the interface.
      // Each of these functions might optionally be
      // pure virtual, and if so might or might not have
      // an implementation in Widget; see Item 27 in [1].
      //
      virtual int DoProcessPhase1( Gadget& );
      virtual int DoProcessPhase2( Gadget& );
      virtual bool DoIsDone();
      // ...
    };
} // namespace nvi_and_Template_Method

namespace aggregate_types {
    struct Point {
        int x, y;
    }; // Aggregate in C++17 and earlier

    struct Circle {
        Point center;
        int radius;
    }; // Aggregate in C++17 and earlier

    // C++20 Example with defaulted constructor
    struct Box {
        int length = 1; // Allowed in C++20
        int width = 1; // Allowed in C++20
        Box() = default; // User-declared defaulted constructor is allowed in C++20
    };

    Point p = {1, 2}; // Aggregate initialization
    Circle c = {{1, 2}, 5}; // Nested aggregate initialization
    Box b = {}; // Uses defaulted values for length and width in C++20
} // namespace aggregate_types

void playground(){
   std::cout << "Playground:\n\n";
   DO_NOT_default_parameters_in_virtual_functions::main();
}