#include <bits/stdc++.h>
using namespace std;

class twoStacks {
    int* arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n = 1000) {
        size = n;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int x) {
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        }
    }

    void push2(int x) {
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        }
    }

    int pop1() {
        if (top1 >= 0) {
            int val = arr[top1];
            top1--;
            return val;
        } else {
            return -1;
        }
    }

    int pop2() {
        if (top2 < size) {
            int val = arr[top2];
            top2++;
            return val;
        } else {
            return -1;
        }
    }
};
