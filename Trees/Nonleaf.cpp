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
    int countNonLeafNodes(Node* root) {
        if (root == nullptr) return 0;

        // If it's a leaf node, don't count it
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }

        return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
    }
};
