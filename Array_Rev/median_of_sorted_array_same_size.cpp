#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int total = n + m;
        
        int i = 0, j = 0;
        int mid1 = -1, mid2 = -1;
        
        for (int k = 0; k <= total / 2; k++) {
            int val;
            if (i < n && (j >= m || a[i] <= b[j])) {
                val = a[i++];
            } else {
                val = b[j++];
            }
            
            if (total % 2 == 0) {
                if (k == total/2 - 1) mid1 = val;
                if (k == total/2) mid2 = val;
            } else {
                if (k == total/2) mid1 = val;
            }
        }
        
        if (total % 2 == 0) {
            return (mid1 + mid2) / 2.0;
        } else {
            return mid1;
        }
    }
};
