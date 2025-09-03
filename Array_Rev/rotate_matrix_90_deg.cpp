#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void swap(int &a , int &b) {
    int temp = a;
    a = b; 
    b = temp;
}
// rotate image by 90 deg
void rotate(vector<vector<int>>& A) {
    int n = A.size();
    // transpose the matrix 
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j <n; j++) {
            swap(A[i][j] , A[j][i]);
        }
    }

    // after making the transpos ethen reverse the matrix 
    for(int i = 0; i <n; i++) {
        reverse(A[i].begin(), A[i].end());
    }
  
}
};