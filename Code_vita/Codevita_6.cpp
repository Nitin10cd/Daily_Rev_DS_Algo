#include <bits/stdc++.h>
using namespace std;

int main () {
    int test;
    cout << "Enter the test cases";
    cin >> test;

    for (int i = 0; i < test; i++) {
        cout << "Enter the candy in ach box";
        int n;
        cin >> n;
        cout << "Enter the candies in each box";
        vector<long long> candy;
        for (int i = 0; i < n; i++) {
            long long val;
            cin >> val;
            candy.push_back(val); 
        }
        sort(candy.begin(), candy.end());
        for (int i = 0; i < n; i++) {
            candy[i] += candy[i  -1];
        }
        int time = 0;
        for (int i = 0; i < n; i++) {
            time+=candy[i];
        }

        cout << time;

    }
}