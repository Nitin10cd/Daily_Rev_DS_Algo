// reverse in between

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode*next;

    ListNode(int val1, ListNode*next1) {
        val = val1;
        next = next1;
    }

    ListNode(int val1) {
        val = val1;
        next = nullptr;
    }
};

ListNode* ConvertArrToLL(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        ListNode* temp = new ListNode(arr[i], nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void Print(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* reverseList(ListNode* head , ListNode*right) {
    ListNode* prev = nullptr;  
    ListNode* current = head;   
    ListNode* next = nullptr;   

    while (current != nullptr && current!=right->next) {
        next = current->next;   
        current->next = prev;   
        prev = current;         
        current = next;         
    }
    
    return prev; 
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
   if (!head || left == right) return head;
   ListNode* dummy = new ListNode(0);
   dummy -> next = head;
   ListNode* prevLeft = dummy;
   for( int i = 0; i < left; i++) {
    prevLeft = prevLeft -> next;
   }

   ListNode* start = prevLeft ->next;
   ListNode* end = start;


   for (int i  =left; i < right; i++) {
    end = end -> next;
   }

   ListNode* nextRight = end ->next;
   end -> next = nullptr;
   ListNode* nextStart = reverseList(start,end);
   prevLeft = nextStart;
   start -> next = nextRight;
   return dummy -> next;
}