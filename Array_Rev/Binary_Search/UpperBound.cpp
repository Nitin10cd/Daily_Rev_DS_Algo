#include<bits/stdc++.h>
using namespace std;

int lastOccurance (vector<int> &num , int target) {
    int low = 0;
    int high = num.size() - 1;
    int last = -1;

    // loop 
    while(low <= high){
        int mid = low + (high - low)/2;
        if(num[mid] == target) {
            last = mid;
            low = mid + 1;
        }else{
            if(num[mid] < target){
                low=(mid+1);
            }else{
                high=mid-1;
            }
        }
    }
    return last;
}

