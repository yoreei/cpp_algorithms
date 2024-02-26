#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <set>

std::string getLineUntil(const std::string& endStr, const std::string& prompt) {
    std::cout << "Enter " << prompt << " (end with " << endStr << "):" << std::endl;

    std::string input = "";
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == endStr) {
            break;
        }
        input += line + "\n"; // Append each line to the input string
    }
    return input;
}

void printSet(const std::set<std::string>& set, std::string& setName) {
    std::cout<< "setName: " << setName << ":" << std::endl;
    for (const auto& name : set) {
        std::cout << name << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const std::set<std::string>& set) {
    for (const auto& element : set) {
        os << element << std::endl;
    }
    return os;
}

namespace tp_regex{
    void main() {
        std::string enumNamesStr = getLineUntil("END", "enumNamesStr");
        std::string toStringeNamesStr = getLineUntil("END", "toStringeNames");

        // Process enum
        std::set<std::string> enumNames;
        {
            enumNamesStr = std::regex_replace(enumNamesStr, std::regex(" "), "");
            std::cout << "enumNamesStr: " << enumNamesStr << std::endl;
            std::regex regexPattern(R"((\w+)=\w+)");
            std::smatch matches;

            auto begin = std::sregex_iterator(enumNamesStr.begin(), enumNamesStr.end(), regexPattern);
            auto end = std::sregex_iterator();

            for (std::sregex_iterator i = begin; i != end; ++i) {
                std::smatch match = *i;
                enumNames.insert(match[1].str());
            }
        }

        // Process tostring function
        std::set<std::string> toStringeNames;
        {
            std::regex regexPattern(R"(case CallFailureReason::(\w+):)");
            std::smatch matches;

            auto begin = std::sregex_iterator(toStringeNamesStr.begin(), toStringeNamesStr.end(), regexPattern);
            auto end = std::sregex_iterator();

            for (std::sregex_iterator i = begin; i != end; ++i) {
                std::smatch match = *i;
                toStringeNames.insert(match[1].str());
            }
        }

        //std::cout << "Extracted enumNames:" << std::endl << enumNames << std::endl;
        //std::cout << "Extracted toStringeNames:" << std::endl << toStringeNames << std::endl;

        {
            std::set<std::string> diff1;
            std::set_difference(enumNames.begin(), enumNames.end(), toStringeNames.begin(), toStringeNames.end(), std::inserter(diff1, diff1.begin()));
            std::cout<< "enumNames - toStringeNames:" << std::endl << diff1;

            std::set<std::string> diff2;
            std::set_difference(toStringeNames.begin(), toStringeNames.end(), enumNames.begin(), enumNames.end(), std::inserter(diff2, diff2.begin()));
            std::cout<< "toStringeNames - enumNames:" << std::endl << diff2;
        }

    }
} // namespace tp_regex