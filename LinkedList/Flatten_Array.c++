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


class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node* current = head;
        while (current) {
            // If child exists
            if (current->child) {
                Node* tempNext = current->next;

                // Link current node with child
                current->next = current->child;
                current->child->prev = current;
                current->child = nullptr;

                // Find the tail of the child list
                Node* tail = current->next;
                while (tail->next) {
                    tail = tail->next;
                }

                // Connect the original next to the tail of child list
                tail->next = tempNext;
                if (tempNext) tempNext->prev = tail;
            }
            current = current->next;
        }

        return head;
    }
};
