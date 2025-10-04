#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int data1, ListNode* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;
    
    while (current != nullptr) {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main (void) {
    return 0;
}