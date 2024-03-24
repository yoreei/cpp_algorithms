#include <iostream>

namespace syntax_literals {


    void main(){
        const char *s = "hello";
        const wchar_t *ws = L"hello";
        const char a[] = "hello";

        std::cout << "Size of s: " << sizeof(s) << std::endl;
        std::cout << "Size of ws: " << sizeof(ws) << std::endl;
        std::cout << "Size of a: " << sizeof(a) << std::endl;
    }

} // namespace syntax_literals
