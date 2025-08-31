#include <bits/stdc++.h>
using namespace std;

// better 
int getLongestSubarray(vector<int>& a, long long k) {
   long long sum = 0;
   map<long long, int> prefixSum;
   int maxLen = 0;
   for (int i = 0; i < a.size(); i++) {
        sum+=a[i];
        if (sum == k) {
            maxLen = max(maxLen, i+1);
        }
        int rem = sum - k;
        if(prefixSum.find(rem)!= prefixSum.end()){
            int len = i - prefixSum[rem];
            maxLen = max(maxLen,len);
        }
        prefixSum[sum] = i;
   }
   return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
