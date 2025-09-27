#include<bits/stdc++.h>
using namespace std;

// house robber problem
int maxMoney( int index, int arr[]){
    if(index < 0) return 0;
    int rob = arr[index] + maxMoney(index - 2, arr);
    int notrob = 0 + maxMoney(index - 1, arr);
    return max(rob, notrob);
}
int main () {
    int n;
    cout << "Enter the no of houses: ";
    cin>> n;
    vector<int> houses(n);
    cout << "Enter the values of houses: ";
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }

    return 0;
}