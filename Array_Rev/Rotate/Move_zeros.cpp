#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0; // pointer for placing non-zero elements

        // move non-zero elements forward
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};