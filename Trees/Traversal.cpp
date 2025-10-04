#include <iostream>
using namespace std;
#include<bits/stdc++.h>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public: 

    Node* root;
    BinaryTree() {
        root = nullptr;
    }

    // function to insert a node 
    Node* InsertNode(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
        if (value < root -> data) {
            root -> left = InsertNode(root -> left, value);
        } else {
            root -> right = InsertNode(root -> right, value);
        }
    }

    // recursive inorder prerder postrder traversal 
       void Inorder(Node* node) {
        if (node == nullptr) return;
        Inorder(node->left);  
        cout << node->data << " ";
        Inorder(node->right);
    }
    void PreOrder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        PreOrder(node->left);  
        PreOrder(node->right);
    }
    void PostOrder(Node* node) {
        if (node == nullptr) return;
        PostOrder(node->left);  
        PostOrder(node->right);
        cout << node->data << " ";
    }


    // Level Order traversal 
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> lvl;

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                lvl.push_back(node -> data);

                if (node -> left != nullptr) q.push(node -> left);
                if (node -> right != nullptr) q.push(node -> right);
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};