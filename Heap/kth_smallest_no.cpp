#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {   
        int n = mat.size();
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;


        for (int i = 0; i < n; i++) {
            pq.push({mat[i][0], {i, 0}});
        }

        int ans = -1;
        while (k--) {
            auto element = pq.top(); pq.pop();
            ans = element.first;
            int row = element.second.first;
            int col = element.second.second;

            if (col + 1 < n) {
                pq.push({mat[row][col + 1], {row, col + 1}});
            }
        }
        return ans;
    }
};

