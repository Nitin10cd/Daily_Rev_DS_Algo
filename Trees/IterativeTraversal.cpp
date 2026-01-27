#include<bits/stdc++.h>
using namespace std;

// Tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:

    // 1️⃣ Preorder: Root -> Left -> Right
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);

            // push right first
            if (node->right) st.push(node->right);
            if (node->left)  st.push(node->left);
        }
        return ans;
    }

    // 2️⃣ Inorder: Left -> Root -> Right
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }

    // 3️⃣ Postorder: Left -> Right -> Root (two stacks)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);

            if (node->left)  st1.push(node->left);
            if (node->right) st1.push(node->right);
        }

        while (!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};
