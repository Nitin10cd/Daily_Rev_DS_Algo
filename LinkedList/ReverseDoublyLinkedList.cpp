#include<bits/stdc++.h>
using namespace std;

struct DLLNode {
    int val;
    DLLNode* next;
    DLLNode* prev;

    DLLNode(int val1, DLLNode* next1 = nullptr, DLLNode* prev1 = nullptr) {
        val = val1;
        next = next1;
        prev = prev1;
    }
};

//brute force 
DLLNode* reverseDLL(DLLNode* head) {
    //  brute force using the stack
    stack<int>  stack;
    DLLNode* temp = head;
    while (temp != NULL)
    {
    stack.push(temp -> val);
    temp = temp -> next;
    }

    temp = head;
    while (temp != nullptr)
    {
       temp -> val = stack.top();
       stack.pop();
       temp = temp -> next;
    }
}

// using the two pointer
DLLNode* reverseDLL(DLLNode* head) {
  DLLNode* temp = nullptr;
  DLLNode* current = head;

  // traverse and swap next and prev with each other for each pass
  while (current != nullptr) {
    temp = current -> prev;
    current -> prev = current -> next;
    current -> next = temp;

    // move to th next dllNode in the original list
    current = current -> prev;
  }
  if (temp != nullptr) {
    head = temp -> prev;
}

return head;
}


// better using the two pointter 


int main(void) {

}