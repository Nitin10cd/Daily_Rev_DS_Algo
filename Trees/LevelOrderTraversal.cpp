// #include<bits/stdc++.h>
// using namespace std;

// class Node {
//   public:
//     int data;
//     Node* left;
//     Node* right;

//     // Constructor
//     Node(int val) {
//         data = val;
//         left = nullptr;
//         right = nullptr;
//     }
// };

// class Solution {
//   public:
//     vector<vector<int>> levelOrder(Node *root) {
//         // code here
//         queue<Node*> q;
//         q.push(root);
//         vector<int> ans;

//         Node* temp;
//         while (!q.empty()) {
//             temp = q.front();
//             q.pop();
//             ans.push_back(temp->data);

//             // inserting the left and the right of the temp dde in the queue
//             if (temp -> left) {
//                 q.push(temp -> left);
//             }
//             if (temp -> right) {
//                 q.push(temp -> right);
//             }
//         }
//     }
//     return ans;
// };

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> result;
        if (!root) return result;  

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();         
            vector<int> currentLevel;      

            for (int i = 0; i < levelSize; i++) {
                Node* node = q.front();
                q.pop();
                currentLevel.push_back(node->data);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(currentLevel);     
        }

        return result;
    }
};
