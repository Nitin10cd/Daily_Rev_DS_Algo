// gfg link:https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

#include<bits/stdc++.h>
using namespace std;

// Basically it is a next Greatest element in the left side
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& price, int n) {
        // code here
        int n = price.size();
        stack<int> st;
        vector<int> ans (n,1);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && price[i] > price[st.top()]){
                ans[st.top()] = st.top() - i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            ans[st.top()] = st.top() + 1;
            st.pop();
        }

        return ans;
    }
};