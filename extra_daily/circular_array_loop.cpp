#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n; 
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue; 
            bool dir = nums[i] > 0;

            int slow = i, fast = i;

            while (true) {
                // move slow one step
                int nextSlow = nextIndex(nums, slow);
                if (nums[nextSlow] == 0 || (nums[nextSlow] > 0) != dir) break;

                // move fast 1st step
                int nextFast = nextIndex(nums, fast);
                if (nums[nextFast] == 0 || (nums[nextFast] > 0) != dir) break;

                // move fast 2nd step 
                nextFast = nextIndex(nums, nextFast);
                if (nums[nextFast] == 0 || (nums[nextFast] > 0) != dir) break;

                slow = nextSlow;
                fast = nextFast;

                if (slow == fast) {
                    if (slow == nextIndex(nums, slow)) break;
                    return true;
                }
            }

            // marked path as visited 
            int j = i;
            while (nums[j] != 0 && (nums[j] > 0) == dir) {
                int next = nextIndex(nums, j);
                nums[j] = 0;
                j = next;
            }
        }
        return false;
    }
};
