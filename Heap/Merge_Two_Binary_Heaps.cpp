#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void heapify(vector<int> &arr, int index, int n){
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != index){
        swap(arr[largest], arr[index]);
        heapify(arr, largest, n);
    }
  }

  vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {

      vector<int> ans = a;
      ans.insert(ans.end(), b.begin(), b.end());

      int k = ans.size();

      for(int i = k/2 - 1; i >= 0; i--){
          heapify(ans, i, k);
      }

      return ans;
  }
};
