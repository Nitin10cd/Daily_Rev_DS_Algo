#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    void mirror(Node* root) {
        // code here
        if (!root) return;
        Node* temp = root -> right;
        root -> right = root -> left;
        root -> left = temp;

        // mirroring 
        mirror(root -> left);
        mirror(root -> right);
    }
};