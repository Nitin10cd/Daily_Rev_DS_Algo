#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;


        vector<int> s(n);
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;

        int ans = 1;
        int i = 2;
        int j = 3;

          while (j < n) {
            int nextNum = (s[j-1] == 1) ? 2 : 1;
            int times = s[i]; 
            for (int k = 0; k < times && j < n; k++) {
                s[j++] = nextNum;
                if (nextNum == 1) ans++;
            }
            i++;
        }

        return ans;

    }
};