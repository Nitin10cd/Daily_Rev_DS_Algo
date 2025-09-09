#include <bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};


// integrating using the slow fast pointer
bool hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) return true;
    }
}


// detect the length of cycle
int findLength (ListNode*fast , ListNode* slow) {
     fast = fast -> next;
    int cnt = 1;
    while (fast != slow) {
        cnt++;
        fast = fast->next;
    }
    return cnt;
}

   ListNode *detectCycle(ListNode *head) {
      ListNode* fast = head;
      ListNode* slow = head;
      while(fast != nullptr && fast->next != nullptr) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow -> next;
                fast = fast -> next;
            }
        }
      }
      return slow;
    }
int main (void) {

}