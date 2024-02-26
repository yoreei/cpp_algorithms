#pragma once

#include <iostream>
#include <vector>
#include "../utils.h"
#include <map>

namespace stl_thinkcell {
    /*
    * 
    * 
    *     { {1, {2, 3}}, {2, {1, 3}}, {3, {1, 2}} }, 1, { 1, 2, 3 }, 3);
    { {1, {2}}, {2, {}}, {3, {4}}, {4, {}} }, 1, { 1, 2 }, 4);
    { {1, {2, 3, 4}}, {2, {}}, {3, {}}, {4, {}} }, 1, { 1, 2, 3, 4 }, 5);
    { {1, {2}}, {2, {3, 4}}, {3, {5}}, {4, {}}, {5, {}} }, 1, { 1, 2, 3, 4, 5 }, 6);
    { {1, {2}}, {2, {1}} }, 1, { 1, 2 }, 7);
    { {1, {2, 3}}, {2, {4}}, {3, {5}}, {4, {}}, {5, {}} }, 1, { 1, 2, 3, 4, 5 }, 8);
    { {1, {2, 3}}, {2, {3}}, {3, {2}} }, 1, { 1, 2, 3 }, 9);
    { {1, {2, 3}}, {2, {1, 3}}, {3, {2, 1}} },
    */

    class _Map : public std::map<int, std::vector<int>> {
        int MyExtract(int key) {
            auto it = this->find(key);
            if (it != this->end()) {
                return it->first;
            }
            return 0;
        }
    };

    void main(){
       
       std::cout << "stl thinkcell" << std::endl;
    }

} // namespace thinkcell
