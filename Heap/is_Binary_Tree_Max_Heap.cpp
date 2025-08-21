#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
  int count(Node* root){
    if(!root) return 0;
    return 1 + count(root->left) + count(root->right);
  }

  bool CBT(Node* root, int index, int total_nodes){
    if(!root) return true;

    if(index >= total_nodes) return false;

    return CBT(root->left, 2*index+1, total_nodes) &&
           CBT(root->right, 2*index+2, total_nodes);
  }

  bool MaxHeap(Node* root){
    if(!root) return true;

    // leaf node
    if(!root->left && !root->right) return true;

    // left child exists
    if(root->left && root->data < root->left->data) return false;

    // right child exists
    if(root->right && root->data < root->right->data) return false;

    // recursively check subtrees
    return MaxHeap(root->left) && MaxHeap(root->right);
  }


  bool isHeap(Node* tree) {
    int num = count(tree);
    return CBT(tree, 0, num) && MaxHeap(tree);
  }
};
