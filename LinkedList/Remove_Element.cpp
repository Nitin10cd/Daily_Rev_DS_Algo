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

  for (int i = 0; i < arr.size(); i++) {
    ListNode* temp = new ListNode(arr[1], nullptr);
    prev -> next = temp;
    prev = temp;
  }
  return head;
}
void Print(ListNode* head) {
  
}



ListNode* removeElements(ListNode* head, int val) {

    while (head != nullptr && head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    ListNode* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->next->val == val) {
            ListNode* delNode = curr->next;
            curr->next = curr->next->next;
            delete delNode;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

int main(void) {
 
}