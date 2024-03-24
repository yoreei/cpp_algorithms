#include <iostream>
#include <type_traits>
#include <functional>
#include <complex>

namespace concepts_hashable{
    template<typename T>
    concept Hashable = requires(T a) {
        { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
    };

    template<Hashable _T>
    void print_hash(const _T& value) {
        std::cout << std::hash<_T>{}(value) << '\n';
    }
    void main(){
        print_hash(42);
        print_hash(3.14);
        print_hash(std::string("Hello, World!"));
    }
} // namespace concepts_hashable

namespace auto_templating{
    void func(auto a)
    {
        std::cout << a;
    }
    // is same as 
    template <typename T>
    void funct2(T a)
    {
        std::cout << a;
    }
    // both of them are inline functions by default (because of templating)
} // namespace auto_templating

namespace NTTP{
    // Non-type template parameters
    template <class _Ty, size_t _Size>
    class array {
    public:
        _Ty _Elems[_Size];
        array() = default;
        array(std::initializer_list<_Ty> list) {
            size_t i = 0;
            for (auto& elem : list) {
                if (i < _Size) {
                    _Elems[i++] = elem;
                }
            }
        }
    };
    void main(){
        array<long long, 10> a;
        std::cout << sizeof(a) << std::endl;
        array<long long, 20> b;
        std::cout << sizeof(b) << std::endl;
    }
}



/*

Template Classes and Functions: Basics of generic programming, allowing for type - agnostic implementations.

Variadic Templates : Enables functions, classes, and structs to accept an arbitrary number of template parameters, useful for creating tuple - like structures, type lists, or forwarding arguments.

Template Specialization : Allows for the customization of templates for specific types to optimize performance or handle special cases.

SFINAE(Substitution Failure Is Not An Error) : Technique for creating conditionally enabled functions based on the success of type substitution in template parameters, fundamental for template metaprogramming.

Template Aliases : Simplifies complex template syntax and can be used to create more readable code or alias template instantiations.

Fold Expressions : Introduced in C++17 to perform operations on all elements of a parameter pack, simplifying variadic template code.

Auto and Decltype : Auto for type inference and decltype for obtaining the type of an expression, both essential in template programming for simplifying type declarations.

If constexpr : Conditional compilation within functions, enabling different code paths based on compile - time conditions, reducing the need for template specialization.

Inline Variables : With C++17, support for inline variables in templates to avoid multiple definitions errors and simplify the management of template static data.

Template Metaprogramming : Writing programs that generate other programs as part of the compilation process, leveraging templates for compile - time computations and logic.

Concepts and Constraints : Introduced in C++20, allowing for specifying explicit requirements on template arguments, improving code readability and compile - time checks.

Modules and Preprocessor : Utilizing C++20 modules to potentially reduce reliance on preprocessor directives and header files, improving compile times and encapsulation.

constexpr and consteval Functions : Writing functions that can be executed at compile - time, crucial for template metaprogramming and optimizing runtime performance.

Template Parameter Packs : Handling an arbitrary number of template parameters, fundamental for variadic templates and metaprogramming techniques.

Class Template Argument Deduction(CTAD) : Automatically deducing the type of class template arguments from the constructor, simplifying template usage.

Lambda Expressions in Template Code : Using lambdas within templates for inline definitions of operations or custom logic, especially with auto parameters in C++20.

Attribute Syntax : Utilizing [[attributes]] to provide additional information to the compiler, influencing optimization, warnings, and code generation in template code.

Preprocessor Directives for Configuration : Using #define, #ifdef, and other directives to configure template libraries or manage template instantiations across different platforms or compiler options.

Type Traits and Type Manipulation : Using the type_traits header for compile - time type information and manipulation, essential for SFINAE and template specialization.

std::enable_if and std::conditional : Conditional type selection and function enabling based on compile - time conditions, integral to writing flexible and type - safe template code.
*/
