// approach based on the next Greater element
#include <bits/stdc++.h>
using namespace std;

// gfg Link: https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &arr){
        // staxk for the operation of the next g elements
        stack<int> st;
        int n = arr.size();
        // for storing the ans
        vector<int> ans(n,-1);

        // iterating through the array and perform the op
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] < arr[i]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
