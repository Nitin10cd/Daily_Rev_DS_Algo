#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> p;

        // Push all elements into the min-heap
        for (int val : arr) {
            p.push(val);
        }

        int cost = 0;
        // Keep combining two smallest ropes
        while (p.size() > 1) {
            int rope1 = p.top(); p.pop();
            int rope2 = p.top(); p.pop();

            int merged = rope1 + rope2;
            cost += merged;

            p.push(merged);
        }

        return cost;
    }
};
