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
    void counting(Node* node, int &sum) {
        if (node == nullptr) return;
        sum += node->data;
        counting(node->left, sum);
        counting(node->right, sum);
    }

    int sumBT(Node* root) {
        int sum = 0;
        counting(root, sum);
        return sum;
    }
};
