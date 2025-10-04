#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

TreeNode* buildTreex(vector<int>& preorder, int preStart, int preEnd, 
    vector<int>& inorder, int inStart, int inEnd, 
    map<int, int>& inMap) {
if (preStart > preEnd || inStart > inEnd) return nullptr;

TreeNode* root = new TreeNode(preorder[preStart]);
int inRoot = inMap[root->data];  
int numsLeft = inRoot - inStart;

root->left = buildTreex(preorder, preStart + 1, preStart + numsLeft, 
           inorder, inStart, inRoot - 1, inMap);
root->right = buildTreex(preorder, preStart + numsLeft + 1, preEnd, 
            inorder, inRoot + 1, inEnd, inMap);
return root;
}

// from inorder and preorder
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
map<int, int> inMap;
for (int i = 0; i < inorder.size(); i++) {
inMap[inorder[i]] = i;
}
return buildTreex(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
}



