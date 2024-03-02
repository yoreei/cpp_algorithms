#pragma once

#include <iostream>
#include <vector>
#include "../utils.h"
#include <map>
#include <chrono>
#include <functional>

/*
# BENCH_TIMES = 1'000'000'000
 
## Debug:

std_func: 8208ms
func_ptr: 1305ms

## Release:

std_func: 2611ms
func_ptr: 0ms
*/

namespace stl_function {
    constexpr unsigned long long BENCH_TIMES = 1'000'000'000;
    int now() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }
    void bench_func(){}
    void main(){
        std::function<void()> func_std = bench_func;
        void (*func_ptr)() = bench_func;
        int start, end;
        start = now();
        for (unsigned long long i = 0; i < BENCH_TIMES; i++) {
            func_std();
        }
        end = now();
        std::cout << "std_func: " << end - start << "ms" << std::endl;

        start = now();
        for (unsigned long long i = 0; i < BENCH_TIMES; i++) {
            func_ptr();
        }
        end = now();
        std::cout << "func_ptr: " << end - start << "ms" << std::endl;
    }

} // namespace stl_function
