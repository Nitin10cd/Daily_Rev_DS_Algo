#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int index = st.top();
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, heights[index] * width);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int index = st.top();
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            ans = max(ans, heights[index] * width);
        }

        return ans;
    }
};
