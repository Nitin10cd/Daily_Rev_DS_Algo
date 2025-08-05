// monotonic stack based problem for next greatest ekement in circular Array
// gfg link: https://www.geeksforgeeks.org/problems/next-greater-element/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < 2 * n; i++) {
            int curr = arr[i % n];
            while (!st.empty() && curr > arr[st.top()]) {
                ans[st.top()] = curr;
                st.pop();
            }

            if (i < n) {
                st.push(i);
            }
        }

        return ans;
    }
};
