#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int low, int high, int target) {
    while(low <= high){
        int mid = low + (high - low)/2;
        if (arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int findPosition(vector<int>& arr, int target) {
    int low = 0, high = 1;

    //expanding the range till the arr[high] >= target
    while(high < arr.size() && arr[high] < target){
        low = high;
        high*=2;

        // condition for encounter overflow in case the array is finite
        if (high >= arr.size()){
            high = arr.size() - 1;
        }

    }
 
    return binarySearch(arr, low, high, target);
}
