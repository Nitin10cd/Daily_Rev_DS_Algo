#include<bits/stdc++.h>
using namespace std;

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

ListNode* insertEnd (ListNode* head , int val) {
    ListNode* newNode;
    newNode = new ListNode(val);
    ListNode* temp = head;
    while(temp != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head3  = NULL;
        while (l1 != NULL && l2 != NULL) {
            int val = l1->val + l2 -> val;
            head3 = insertEnd(head3 , val);
            l1 = l1 -> next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            head3 = insertEnd(head3 , l1->val);
            l1 = l1 -> next;
        }
        while (l2 != NULL) {
            head3 = insertEnd(head3,l2->val);
            l2 = l2->next;
        }
    return head3;
}