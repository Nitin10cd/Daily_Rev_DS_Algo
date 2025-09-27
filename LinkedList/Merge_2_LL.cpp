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
    ListNode*newNode;
    newNode = new ListNode(val);
    if (head == NULL) {
        return newNode;
    }
    
    ListNode* temp = head;
    while(temp != NULL) {
        temp = temp->next;
    }
    temp -> next = newNode;
    return head;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* temp1 = list1;
    ListNode* temp2 = list2;
    ListNode* Merge;

    while (temp1 != NULL && temp2 != NULL) {
        int val1 = temp1->val;
        int val2 = temp2->val;
        if (val1 <= val2) {
            Merge = insertEnd(Merge , val1);
            temp1 = temp1 -> next;
        } else {
            Merge = insertEnd(Merge , val2);
            temp2 = temp2 -> next;
        }
    }

    while (temp1!= NULL) {
         Merge = insertEnd(Merge , temp1->val);
         temp1 = temp1 -> next;
    }
    while (temp2!= NULL) {
         Merge = insertEnd(Merge , temp2->val);
         temp1 = temp2 -> next;
    }
    return Merge;
}

int main (void) {
    ListNode* list1 = new ListNode(1);
    list1 = insertEnd(list1, 3);
    list1 = insertEnd(list1, 5);

    ListNode* list2 = new ListNode(2);
    list2 = insertEnd(list2, 4);
    list2 = insertEnd(list2, 6);

    ListNode* mergedList = mergeTwoLists(list1, list2);
    while (mergedList != NULL) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    return 0;
}