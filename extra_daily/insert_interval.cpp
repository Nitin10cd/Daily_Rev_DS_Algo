#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        // result 
        vector<vector<int>> result;
        int i = 0, n = intervals.size();

        // adding intervals in the array which comme before the the new onterval or we can say non coflicted
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // now adding the conflicting intervals
        while(i < n && intervals[i][0] <= newInterval[1]) {
            // minimum element obv for the start
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            // max element obv for the end 
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }

        // add in the result
        result.push_back(newInterval);

        // now all the last non conflicting elements
        while(i < n){
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};