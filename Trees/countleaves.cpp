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
// Class Solution
class Solution {
  public:
    int countLeaves(Node* root) {
        if (root == nullptr) return 0;

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        return countLeaves(root->left) + countLeaves(root->right);
    }
};
