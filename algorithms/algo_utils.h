#pragma once

#include <string>
#include <vector>

std::string toStr(std::vector<int> vect)
{
    std::string output;
    auto iter = vect.begin();
    if (iter == vect.end())
    {
        return "<EMPTY>";
    }
    output.append(std::to_string(*iter));
    ++iter;
    while (iter != vect.end()) {
        output.append(", " + std::to_string(*iter));
        ++iter;
    }
    return output;
}