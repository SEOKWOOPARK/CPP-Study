#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Unlike map or set, unordered containers use a hash table internally
// Not keeping elements sorted
// Operation -> O(1) on average and O(n) on the worst collision case
// Slightly higher memory overhead (because of hashing buckets).
int main() {

   unordered_set<string> s1 = {"one", "three", "four", "four", "two"};

   for (string x: s1) {
      cout << x << " ";
   }

   cout << endl;
   cout << "----------------------" << endl;

   unordered_map<string, int> m1 = {{"one", 1}, {"two", 2}};
   m1["five"] = 5;
   m1["five"] = 5;
   m1.insert({"six", 6});

   for (const auto& pair: m1) {
      cout << pair.first << " " << pair.second << endl;
   }

   return 0;
}