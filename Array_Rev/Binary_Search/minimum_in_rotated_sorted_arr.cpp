#include<bits/stdc++.h>
using namespace std;

#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
       int start = 0;
       int end = arr.size() - 1;

       // edge cases if the single elememt exists
       if (arr.empty()) return -1;
       if (arr.size() == 1) return arr[0];

       while(start < end){
        int mid = start + (end - start)/2;

        if (arr[mid] > arr[end]){
            start = mid + 1;
        }else {
            end = mid;
        }
       }

       return arr[start];
    }
};
