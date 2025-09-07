#include<bits/stdc++.h>
using namespace std;

// Recursive way 
// int f(int ind, vector<int> &heights) {
//     if (ind == 0) return 0;
//     int left = f(ind-1, heights)+abs(heights[ind] - heights[ind - 2]);
//     int right = INT_MAX;
//     if (ind > 1) right = f(ind-2,heights) + abs(heights[ind] - heights[ind - 2]);
//     return min(left,right);
// }

// int frogJump(int n , vector<int> &heights) {
//     return f(n-1, heights);
// }


// implementing one d array using the dp array (tabulation)
int f(int ind, vector<int> &heights, vector<int>  &dp) {
    if (ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int left = f(ind-1, heights, dp)+abs(heights[ind] - heights[ind - 2]);
    int right = INT_MAX;
    if (ind > 1) right = f(ind-2,heights, dp) + abs(heights[ind] - heights[ind - 2]);
    return dp[ind] = min(left,right);
}

int frogJump(int n , vector<int> &heights) {
    vector<int> dp(n+1, -1);
    return f(n-1, heights, dp);
}

