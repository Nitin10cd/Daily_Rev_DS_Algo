#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode* prev;

    ListNode(int data1, ListNode* next1 = nullptr, ListNode* prev1 = nullptr) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};


 ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) return nullptr;
    if (head -> next == nullptr) return head;

    ListNode* odd = head;
    ListNode* even = head;
    ListNode*  evenHead = head -> next;

    while (even != nullptr && even -> next != nullptr){
        odd -> next = odd -> next -> next;
        even -> next = odd ->next -> next;

        odd = odd -> next;
        even = even -> next;
    }

    odd -> next = evenHead;
    return head;
}