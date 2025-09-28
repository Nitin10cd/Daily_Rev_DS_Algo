#include <iostream>
#include <vector>
using namespace std;

int path(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    cout << "Enter the number of test cases: ";
    int test;
    cin >> test;

    for (int i = 0; i < test; i++) {
        cout << "Enter the number of rows and columns: ";
        int m, n;
        cin >> m >> n;

        cout << "Number of unique paths: " << path(m, n) << endl;
    }
    return 0;
}
