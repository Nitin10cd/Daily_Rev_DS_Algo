#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    void Total (Node* node, int &count) {
       if (node == nullptr) return;
        count++;
        Total(node -> left, count);
        Total(node -> right, count);
    }
    int getSize(Node* node) {
        int count = 0;
        Total(node, count);
        return count;
    }
};