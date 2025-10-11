#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    bool isCousins(Node *root, int x, int y)
    {
        if (!root)
            return false;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            bool foundX = false, foundY = false;

            for (int i = 0; i < n; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (curr->left && curr->right)
                {
                    if ((curr->left->data == x && curr->right->data == y) ||
                        (curr->left->data == y && curr->right->data == x))
                    {
                        return false; // same parent => not cousins
                    }
                }

                if (curr->data == x)
                    foundX = true;
                if (curr->data == y)
                    foundY = true;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            if (foundX && foundY)
                return true;
            if (foundX || foundY)
                return false;
        }

        return false;
    }
};
