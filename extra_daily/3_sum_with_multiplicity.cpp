#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            int t = target - arr[i];
            int j = i + 1, k = n - 1;

            while (j < k) {
                if (arr[j] + arr[k] < t) {
                    j++;
                } else if (arr[j] + arr[k] > t) {
                    k--;
                } else {
                    if (arr[j] != arr[k]) {
                        int leftCount = 1, rightCount = 1;
                        while (j + 1 < k && arr[j] == arr[j+1]) {
                            leftCount++; j++;
                        }
                        while (k - 1 > j && arr[k] == arr[k-1]) {
                            rightCount++; k--;
                        }
                        ans += (long long)leftCount * rightCount;
                        ans %= MOD;
                        j++; k--;
                    } else {
                        long long m = k - j + 1;
                        ans += m * (m - 1) / 2;
                        ans %= MOD;
                        break; 
                    }
                }
            }
        }
        return (int)ans;
    }
};
