#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1 = nullptr , Node* prev1 = nullptr) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node * removeDuplicates(struct Node *head)
{
    Node* temp = head;
    Node* nextNode;
    Node* duplicate;

    while (temp != nullptr && temp -> next != nullptr) {
        nextNode = temp -> next;
        while (temp != nullptr && temp -> data == nextNode -> data) {
            duplicate = nextNode;
            nextNode = nextNode -> next;
            free(duplicate);
        }
        temp -> next = nextNode;
        if (nextNode) {
            nextNode -> prev = temp;
            temp = temp -> next;
        }
        return head;
    }
   
}

int main (void) {

}