#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> result;
        priority_queue<int> left; // max heap
        priority_queue<int, vector<int>, greater<int>> right; // min heap
        
        for (int num : arr) {
       
            if (left.empty() || num <= left.top()) {
                left.push(num);
            } else {
                right.push(num);
            }
            if ((int)left.size() > (int)right.size() + 1) {
                right.push(left.top());
                left.pop();
            } else if ((int)right.size() > (int)left.size()) {
                left.push(right.top());
                right.pop();
            }

         
            if (left.size() == right.size()) {
                double median = (left.top() + right.top()) / 2.0;
                result.push_back(median);
            } else {
                result.push_back(left.top());
            }
        }
        return result;
    }
};
