#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    int pairSum(ListNode* head) {
  
        // first break the linkedlist into two parts
        ListNode* slow = head;
        ListNode* fast = head;

        // find the middle 
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // reverse the half of the lokedlist
        ListNode* prev = nullptr;
        while (slow != nullptr) {
            ListNode*nextNode = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = nextNode;
        }

        // compute the maximum twin
        int maxSum = 0;
        ListNode* firsthalf = head;
        ListNode* secondhalf = prev;

        while (secondhalf != nullptr) {
            int sum = firsthalf -> val + secondhalf -> val;
            maxSum = max(maxSum,sum);
            firsthalf = firsthalf->next;
            secondhalf = secondhalf -> next;
        }
        return maxSum;
    }
};
