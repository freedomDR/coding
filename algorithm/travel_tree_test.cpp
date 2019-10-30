#include<bits/stdc++.h>
#include "b_tree.h"
using namespace std;

void build(ptr &root)
{
    root->addLeft(make_unique<Tree>(3));
    root->addRight(make_unique<Tree>(8));
    root->left->addLeft(make_unique<Tree>(2));
    root->left->addRight(make_unique<Tree>(4));
    root->right->addLeft(ptr(new Tree(7)));
    root->right->addRight(ptr(new Tree(9)));
}

void preorderTravel(ptr &root)
{
    if(root == NULL) return;
    cout << root->val << endl;
    preorderTravel(root->left);
    preorderTravel(root->right);
}

void nonRecur_preorderTravel(ptr &root)
{
    stack<ptr> s;
    s.push(root);
    while(!s.empty())
    {
        root = s.top();
        s.pop();
        cout << root->val << endl;
        if(root->right != NULL) s.push(root->right);
        if(root->left != NULL) s.push(root->left);
    }
}

void nonRecurInorderTravel(ptr &root)
{
    stack<ptr> s;
    while(!s.empty() || root != NULL)
    {
        while(root!=NULL)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        cout << root->val << endl;
        root = root->right;
    }
}

void nonRecurPostorderTravel(ptr &root)
{
    stack<ptr> s;
    ptr last = NULL;
    while(!s.empty() || root != NULL)
    {
        while(root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        if(root->right == NULL || last == root->right)
        {
            cout << root->val << " ";
            last = root;
            s.pop();
            root = NULL;
        }
        else
        {
            root = root->right;
        }
    }
}

int main()
{
    ptr root(new Tree(5));
    build(root);
    /* nonRecur_preorderTravel(root); */
    /* nonRecurInorderTravel(root); */
    nonRecurPostorderTravel(root);
    return 0;
}
