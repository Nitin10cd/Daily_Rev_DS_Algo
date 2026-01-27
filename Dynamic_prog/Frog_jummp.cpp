#include <bits/stdc++.h>
using namespace std;

// RECURSION (DO NOT UNCOMMENT)
// class Solution {
// public:
//    int f (int idx, vector<int> &heights){
//     if (idx == 0) return 0;
//     int left = f(idx - 1, heights) + abs(heights[idx] - heights[idx-1]);
//     int right = INT_MAX;
//     if (idx > 1)
//         right = f(idx - 2, heights) + abs(heights[idx] - heights[idx-2]);
//     return min(left, right);
//    }
// };

// DYNAMIC PROGRAMMING (MEMOIZATION)
class Solution {
public:
    bool canCross(vector<int>& stones) {
        std::unordered_map<int, std::unordered_set<int>> dp;
        for (int stone : stones) {
            dp[stone] = std::unordered_set<int>();
        }
        dp[0].insert(0);

        for (int stone : stones) {
            for (int jump : dp[stone]) {
                for (int jumpDistance : {jump - 1, jump, jump + 1}) {
                    if (jumpDistance > 0 && dp.find(stone + jumpDistance) != dp.end()) {
                        dp[stone + jumpDistance].insert(jumpDistance);
                    }
                }
            }
        }

        return !dp[stones.back()].empty();        
    }
};