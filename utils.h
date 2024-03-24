#pragma once

#include <iostream>
#include <source_location>
#include <string_view>
 
inline void log_full(const std::string_view message,
         const std::source_location location =
               std::source_location::current())
{
    std::clog << location.file_name() << '('
              << location.line() << ':'
              << location.column() << ") `"
              << location.function_name() << "`: "
              << message << '\n';
}

inline void log(const std::string_view message,
         const std::source_location location =
               std::source_location::current())
{
    std::clog << location.line() << ':'
              << message << '\n';
}

inline void except(){
    throw std::runtime_error(std::string("ho "));
}