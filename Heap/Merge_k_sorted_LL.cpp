#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;  
    }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, Compare> pq;

        
        for (Node* head : arr) {
            if (head != NULL) {
                pq.push(head);
            }
        }

        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (!pq.empty()) {
            Node* temp = pq.top();
            pq.pop();

            tail->next = temp;
            tail = tail->next;

            if (temp->next != NULL) {
                pq.push(temp->next);
            }
        }

        return dummy->next;
    }
};
