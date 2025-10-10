#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1) {
            if (seen.count(n)) {
                return false;
            }

            seen.insert(n);

            int total_sum = 0;

            while (n > 0) {
                int digit = n % 10;
                total_sum += digit * digit;
                n /= 10;
            }

            n = total_sum;
        }
    }
};