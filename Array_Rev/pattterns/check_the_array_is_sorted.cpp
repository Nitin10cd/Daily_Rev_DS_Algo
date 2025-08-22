#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int m = nums.size();

        for(int i = 0; i < m; i++){
            if(nums[i] > nums[(i+1)%m]){
                count++;
            }
        }
        return count <= 1;
    }
};