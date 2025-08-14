#include <bits/stdc++.h>
using namespace std;

// APPROCH 2 using one Stack (if we have the nos b/w 1 to 99)
class Solution
{
    stack<int> st;

public:
    Solution()
    {

    }

    void push(int x)
    {
        if (st.empty())
        {
            st.push(x * 100 + x);
        }
        else
        {
            int prevMin = st.top() % 100;      // for getting the previous min value
            st.push(x * 100 + min(x, prevMin)); // method
        }
        cout << "Pushed: " << x << endl;
    }

    void pop()
    {
        if (st.empty())
        {
            cout << "Empty Stack" << endl;
        }
        else
        {
            int ele = st.top();
            st.pop();
            cout << "Popped element: " << ele / 100 << endl; 
        }
    }

    int peek()
    {
        if (!st.empty())
        {
            int val = st.top() / 100; 
            cout << "Top element: " << val << endl;
            return val;
        }
        cout << "Empty Stack" << endl;
        return -1;
    }

    int getMin()
    {
        if (!st.empty())
        {
            int minVal = st.top() % 100; 
            cout << "Current min: " << minVal << endl;
            return minVal;
        }
        cout << "Empty Stack" << endl;
        return -1;
    }
};


// APPROCH 1: USING THE 2 STACKS (NOT THAT MUCH GOOD)
// class Solution
// {
//     stack<int> st;
//     stack<int> minStack;

// public:
//     Solution()
//     {

//         minStack.push(INT_MAX);
//     }

//     // Add an element to the top of Stack
//     void push(int x)
//     {
//         st.push(x);

//         if (minStack.empty() || x <= minStack.top())
//         {
//             minStack.push(x);
//         }
//         else
//         {
//             minStack.push(minStack.top()); 
//         }
//     }

//     // Remove the top element from the Stack

//     void pop()
//     {
//         // code here
//         if (st.empty())
//         {
//             cout << "Empty Stack";
//         }
//         else
//         {
//             int ele = st.top();
//             st.pop();
//             minStack.pop();
//             cout << "Ele: " << ele << endl;
//         }
//     }

//     // Returns top element of the Stack
//     int peek()
//     {
//         // code here
//         if (!st.empty())
//             return st.top();
//         return -1;
//     }

//     // Finds minimum element of Stack
//     int getMin()
//     {
//         // code here
//         if (!minStack.empty())
//             return -1;
//         return minStack.top();
//     }
// };