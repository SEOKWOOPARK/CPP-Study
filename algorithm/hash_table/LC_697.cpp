#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& a) {
        unordered_map<int,int> cnt, first;
        int degree = 0;
        int answer = a.size();

        for (int i = 0; i < a.size(); ++i) {
            int x = a[i];
            if (!first.count(x)) {
                first[x] = i;
            }

            ++cnt[x];

            if (cnt[x] > degree) {
                degree = cnt[x];
                answer = i - first[x] + 1;
            } else if (cnt[x] == degree) {
                answer = min(answer, i - first[x] + 1);
            }
        }
        return answer;
    }
};