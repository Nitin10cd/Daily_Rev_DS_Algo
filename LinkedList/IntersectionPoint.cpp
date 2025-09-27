#include<bits/stdc++.h>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
   ListNode* pullerFunc(ListNode* temp, int cnt) {
        
    }

    ListNode* BettergetIntersectionNode(ListNode* headA, ListNode* headB) {
     
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
      if (headA == nullptr || headB == nullptr) return nullptr;
      ListNode* tempA = headA;
      ListNode* tempB = headB;

      // traversing the both linkedlist
      while (tempA != tempB) {
          if (tempA == nullptr) {
              tempA = headB;
          } else {
              tempA = tempA->next;
          }
          if (tempB == nullptr) {
              tempB = headA;
          } else {
              tempB = tempB->next;
          }
      }
      return tempA;
    }