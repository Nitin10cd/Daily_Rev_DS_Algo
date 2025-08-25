#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int firstOccurance (vector<int> &num , int target) {
    int low = 0;
    int high = num.size() - 1;
    int first = -1;

    while(low <= high){
       int mid = low + (high-low)/2;
       if(num[mid] == target){
        first = mid;
        high = mid - 1;
       }else{
        if(num[mid] < target){
        low = mid + 1;
       }else{
        high = mid- 1;
       }
       }
    }

    return first;
}

int lastOccurance (vector<int> &num , int target) {
    int low = 0;
    int high = num.size() - 1;
    int last = -1;

    while(low <= high) {
        int mid = low + (high -low)/2;
        if (num[mid] == target) {
            last = mid;
            low = mid + 1;
        }
        else {
            if (num[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return last;
}


vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        ans[0] = firstOccurance(nums,target);
        ans[1] = lastOccurance(nums , target);

        return ans;
}
};