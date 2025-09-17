#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

vector<pair<int, int>> findPairsWithGivenSum(Node* head, int target) {
    // apply two pointer technique
    vector<pair<int,int>> ans;
    Node* left = head;
    Node* right = head;

    // move to the right node to the last node
    while (right -> next != nullptr) {
        right = right -> next;
    }

    // using the two pointer here 
    while (left != right && left -> data < right -> data) {
        int sum = left -> data + right -> data;
        if (sum == target) {
            ans.push_back({left -> data, right -> data});
            left = left -> next;
            right = right -> prev;
        }
        else if (sum > target) {
            right = right -> prev;
        }
        else {
            left = left -> next;
        }
    }
    return ans;
}