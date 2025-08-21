// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class Solution {
  public:
    void inorder(Node *root, vector<int> &ans){
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    void postOrder(Node* root, vector<int> &ans, int &index){
        if(!root) return;

        postOrder(root->left, ans, index);
        postOrder(root->right, ans, index);

        root->data = ans[index++];
    }

    void convertToMaxHeapUtil(Node* root) {
        vector<int> ans;
        inorder(root, ans); 

        int index = 0;
        postOrder(root, ans, index);
    }
};
