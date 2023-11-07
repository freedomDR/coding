#include <bits/stdc++.h>

typedef struct InternalNode
{
    InternalNode *pre;
    InternalNode *next;
    int val;
    InternalNode(int val_): val(val_) {}
}Node;

Node* initLinkList()
{
    Node *head = new Node(-1);
    return head;
}

void singleLinkListAdd(Node *head, int v)
{
    if(head == nullptr)
    {
        std::cerr << "head is nullptr" << std::endl;
        return;
    }
    while(head->next != nullptr)
    {
        head = head->next;
    }
    head->next = new Node(v);
}

void printLinkList(Node *head)
{
    std::cout << "LinkList: ";
    while(head!=nullptr)
    {
        std::cout << head->val;
        head = head->next;
        if(head!=nullptr) std::cout << "->";
    }
    std::cout << std::endl;
}

void deleteLinkList(Node *node)
{
    while(node!=nullptr)
    {
        Node *tmp = node;
        node = node->next;
        delete tmp;
    }
}

void removeNode(Node *head, Node *node)
{
    while(head!=nullptr&&head->next!=node)
    {
        head = head->next;
    }
    head->next = head->next->next;
    delete node;
}

void testLinkList()
{
    std::cout << "Test single link list" << std::endl;
    Node *head = initLinkList();
    std::cout << "head->val: " << head->val << "\nhead->next: " << head->next << std::endl;
    for(int i = 1; i < 10; i++)
        singleLinkListAdd(head, i);
    removeNode(head, head->next);
    printLinkList(head);
    deleteLinkList(head);
}

int main()
{
    testLinkList();
    return 0;
}
