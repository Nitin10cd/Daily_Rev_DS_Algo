#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int val1, ListNode*next1) {
        val = val1;
        next = next1;
    }

    ListNode(int val1) {
        val = val1;
        next = nullptr;
    }
};

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = head;

    while (fast != nullptr && fast -> next != nullptr) {
        prev = slow;
        slow = slow -> next;
        fast = fast -> next ->next;
    }
    return prev;
}