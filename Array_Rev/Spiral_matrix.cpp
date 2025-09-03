// making the spiral matrix into a normal matrix 
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      // ans
      vector<int> ans;
      if (matrix.empty() || matrix[0].empty()) {
        return ans;
      }

      int  top = 0;
      int bottom = matrix.size() - 1;
      int left = 0;
      int right = matrix[0].size() - 1;

      // looping and managin the whole iteration through this
      while (top <= bottom && left <= right) {

        // traverse from left to right
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // traverse from top to bottom
         for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

        // traverse from the right to left 
        
            if (top <= bottom) { 
                // Traverse from right to left along the bottom row
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
             if (left <= right) { 
                // Traverse from bottom to top along the left column
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
      }

      return ans;
    }
};
