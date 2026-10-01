#include <cstdint>

class Solution {
public:
    int mySqrt(int x) {
        std::int64_t r = x;

        while (r * r > x) {
            r = (r + x / r) / 2;
        }

        return static_cast<int>(r);
    }
};