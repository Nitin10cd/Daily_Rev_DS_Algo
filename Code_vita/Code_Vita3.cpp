#include<bits/stdc++.h>
using namespace std;

// frog jump like question in the dp

// without dp
// int totalWays(int n) {
//     if (n == 0 || n == 1) {
//         return 1;
//     }
//     return totalWays(n-1) + totalWays(n-2);
// }

// int main () {
//     int n;
//     cout << "enter the number";
//     cin >> n;

//     int ans = totalWays(n);
//     cout << ans;
//     return 0;
// }

int totalWays(int n , int dp[]) {
    if (n == 0 || n == 1) {
        return 1;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    dp[n] = totalWays(n-1, dp) + totalWays(n-2, dp);
    return dp[n];
}

int main () {
    int n;
    cout << "enter the number";
    cin >> n;
    int dp[n+1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 1; 
    int ans = totalWays(n,dp);
    cout << ans;
    return 0;
}

