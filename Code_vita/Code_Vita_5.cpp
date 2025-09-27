#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter the number n:";
    int n;
    cin >> n;
    cout << "Enter the array k:";
    int k;
    int count = 0;
    for (int i = n; i >= 1; i--){
        if (n % i == 0){
            count++;
            if (count == k){
                cout << i;
                break;
            }
        }
    }
    if (count < k){
        cout << -1;
    }
    return 0;
}