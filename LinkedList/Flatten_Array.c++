#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* child;

    Node(int data1, Node* next1 = nullptr , Node* child1) {
        data = data1;
        next = next1;
        child = child1;
    }
};

// function for merging two linkedList
Node* merge (Node*l1 , Node*l2) {
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1 -> data <= l2 -> data) {
            res -> child = l1;
            l1 = l1 -> child;
        } else {
            res -> child = l2;
            res = l2;
            l2 = l2 -> child;
        }

        res -> next = nullptr;
    }

    if (l1) res -> child = l1;
    else res -> child = l2;

    if (dummyNode->child) dummyNode -> child -> next = nullptr;
    return dummyNode -> child;
}

Node* flatten (Node* head) {
   if (head == nullptr) return head;
   if (head -> next = nullptr) return head;

   Node* mergeHead = flatten(head -> next);
   head = merge(head,mergeHead);
   return head;
}
