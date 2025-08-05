#include<bits/stdc++.h>
using namespace std;

struct Node {
    struct Node*next;
    int data;
};

class Stack {
    private :
    Node*topNode;
    int size = 10;

    public: 
    Stack () {
        topNode = nullptr;
    }

    Stack () {
        while(!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode -> data = value;
        newNode -> next = topNode;
        topNode = newNode;
        size+=1;
    }

    void pop() {
        if(isEmpty()) {
            cout<< "Stack is in underflow";
            return;
        }
        Node*temp = topNode;
        topNode = topNode -> next;
        delete temp;
        size-=1;
    }

};