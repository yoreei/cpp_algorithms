#include <iostream>

namespace syntax_legacy {

    typedef struct tagWNDCLASSEXA {
        int cbSize;
        unsigned int style;
        const char* lpszClassName; // Changed char* to const char*
    } WNDCLASSEXA, *PWNDCLASSEXA;

    void main_impl() { // Changed void to int for main function
        WNDCLASSEXA wc = {0};
        wc.cbSize = sizeof(WNDCLASSEXA);
        wc.style = 0;
        wc.lpszClassName = "myclass"; // Changed to const char*
        std::cout << "Size of wc: " << sizeof(wc) << std::endl;
    }

} // namespace syntax_legacy