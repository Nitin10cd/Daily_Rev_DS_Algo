#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous smaller element
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next smaller element
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Fill ans[]: arr[i] is minimum in window of size right[i]-left[i]-1
        for(int i = 0; i < n; i++){
            int len = right[i] - left[i] - 1;
            ans[len-1] = max(ans[len-1], arr[i]);
        }

        // Fill empty entries
        for(int i = n-2; i >= 0; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }

        return ans;
    }
};
