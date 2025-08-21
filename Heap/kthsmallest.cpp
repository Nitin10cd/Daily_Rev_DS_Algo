#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
   
  int kthSmallest(vector<int> &arr, int k) {
       int l = 0;
       int r = arr.size() - 1;

       // Max heap
       priority_queue<int>p;
       for(int i = 0; i < k; i++){
        p.push(arr[i]);
       }

       // traversing 
       for(int i = k; i <=r; i++){
        if(arr[i] < p.top()){
            p.pop();
            p.push(arr[i]);
        }
       }

       return p.top();
    }

};