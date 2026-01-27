#include<bits/stdc++.h>
using namespace std;

// Tree node
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
    void calcPreOrder(TreeNode* node, vector<int> & ans){
        ans.push_back(node -> val);
        if (node -> left) calcPreOrder(node->left, ans);
        if (node -> right) calcPreOrder(node -> right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        calcPreOrder(root,ans);
        return ans;
    }
};