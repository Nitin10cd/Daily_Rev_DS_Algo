#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Max-heap for K1 smallest
        priority_queue<long long> p1;
        for (long long i = 0; i < N; i++) {
            p1.push(A[i]);
            if (p1.size() > K1) {
                p1.pop();
            }
        }
        long long first = p1.top(); 

        // Max-heap for K2 smallest
        priority_queue<long long> p2;
        for (long long i = 0; i < N; i++) {
            p2.push(A[i]);
            if (p2.size() > K2) {
                p2.pop();
            }
        }
        long long second = p2.top();

        long long sum = 0;
        for (long long i = 0; i < N; i++) {
            if (A[i] > first && A[i] < second) {
                sum += A[i];
            }
        }

        return sum;
    }
};
