#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &arr , int x) {
    int low = 0; int high = arr.size()-1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}