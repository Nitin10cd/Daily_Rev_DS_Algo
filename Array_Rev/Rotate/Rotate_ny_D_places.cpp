#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void myReverse(vector<int>& arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  
        myReverse(nums, 0, n-k-1);
        myReverse(nums, n-k, n-1);
        myReverse(nums, 0, n-1);
    }
};

