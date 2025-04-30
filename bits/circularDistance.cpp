#include <iostream>
#include <array>
#include <cstdint>

// Allows us to treat uin64_t as a ring, using the fact that unsigned integer overflow/underflow is well-defined.

using Vector2 = std::array<float, 2>;

uint32_t twosComplement(uint32_t value) {
    // Example: twosComplement(uint32_t(-1)) == 1
    return ~value + 1u;
}

Vector2 circularDistance(const std::array<uint32_t, 2>& position1,
                         const std::array<uint32_t, 2>& position2) {
    // For example: distance between UINT(1) and UINT_MAX is -2 (go backward)
    // distance between UINT_MAX and UINT(1) is 2 (go forward)
    //
    // 'Why not use signed integers?': signed integer overflow is undefined behavior in C++. Unsigned
    // integer overflow is well-defined and we use this to our advantage.

    auto unsignedWrapAroundOccurred = [](const uint32_t value) {
        constexpr uint32_t HALF = std::numeric_limits<uint32_t>::max() / 2;
        return value > HALF;
    };

    Vector2 result;
    for (int i = 0; i < 2; ++i) {
        uint32_t diff = position1[i] - position2[i]; // intentional unsigned wrap-around
        if (unsignedWrapAroundOccurred(diff)) {
            result[i] = -float(twosComplement(diff));
        } else {
            result[i] = float(diff);
        }
    }
    return result;
}

int main() {

    return 0;
}



