#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);

        int positive = 0;
        int negative = 1;

        for (int num : nums) {
            if (num < 0) {
                ans[negative] = num;
                negative+=2;
            }else {
                ans[positive] = num;
                positive += 2;
            }
        }
        return ans;
    }
};
