#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};
Node* segregate(Node* head) {
    Node*temp = head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    while (temp) {
        if (temp ->data == 0) {
            zero -> next = temp;
            zero = zero -> next;
        } else if (temp -> data == 1) {
            one -> next = temp;
            one = one -> next;
        } else {
            two -> next = temp;
            two = two -> next;
        }

        temp = temp->next;
    }

    zero -> next = (oneHead->next) ? (oneHead -> next) : (twoHead->next);
    one -> next = twoHead->next;
    two->next = nullptr;

    Node* newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
        // Add code here
}
int  main (void) {

}