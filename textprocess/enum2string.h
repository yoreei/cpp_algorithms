#include <iostream>
#include <string>
#include <vector>
#include <regex>

namespace enum2string {
    void main() {
        std::string line;
        std::vector<std::string> lines;
        std::regex enumRegex(R"(^\s*(\w+)\s*=\s*\w+)");
        std::regex commentRegex(R"(^\s*//(.+))");
        std::regex emptyLineRegex(R"(^\s*$)");
        std::smatch match;

        while (std::getline(std::cin, line) && line != "END") {
            lines.push_back(line);
        }

        std::cout << "std::string callFailureReasonToString(const CallFailureReason reason)\n{\n    switch (reason)\n    {\n";

        for (const auto& l : lines) {
            if (std::regex_search(l, match, enumRegex)) {
                std::cout << "        case CallFailureReason::" << match[1] << ": return \"" << match[1] << "\";\n";
            } else if (std::regex_search(l, match, commentRegex) || std::regex_search(l, match, emptyLineRegex)) {
                std::cout << l << "\n";
            }
        }

        // Close the switch and function
        std::cout << "        default:\n            return \"Unknown CallFailureReason: \" + std::to_string(static_cast<int>(reason));\n    }\n}\n";
    }
} // namespace enum2string
