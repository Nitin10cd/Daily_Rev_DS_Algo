#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {

}

int maximalRectangle(vector<vector<char>>& matrix) {
  int ans = 0;
  int row = matrix.size();
  int col = matrix[0].size();
  vector<int> heights(col,0);

  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
        if (matrix[i][j] == '0'){
            heights[j] = 0;
        }else{
            heights[j] += 1;
        }
    }
    ans = max(ans,largestRectangleArea(heights));
  }
}
