#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int height(TreeNode* root, bool &isBal) {
     if (root == nullptr) return 0;
     int leftHeight = height(root->left, isBal);
     int rightHeight = height(root -> right , isBal);
     if (abs(leftHeight - rightHeight) > 1) isBal = false;
     return max(leftHeight, rightHeight) + 1;
     

}

bool isBalanced(TreeNode* root) {
    bool isBal = true;
    height(root, isBal);
    return isBal;
}
};