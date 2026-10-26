#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int answer = 0;

        while (n >= 5) {
            n /= 5;
            answer += n;
        }

        return answer;
    }
};