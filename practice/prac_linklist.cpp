#include <bits/stdc++.h>

typedef struct InternalNode
{
    InternalNode *pre;
    InternalNode *next;
    int val;
    InternalNode(int val_): val(val_) {}
}Node;

Node* initSingleLinkList()
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
    int cnt = 0;
    while(head!=nullptr)
    {
        cnt++;
        std::cout << head->val;
        head = head->next;
        if(cnt!=1&&head!=nullptr) std::cout << "->";
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

void testSingleLinkList()
{
    std::cout << "Test single link list" << std::endl;
    Node *head = initSingleLinkList();
    std::cout << "head->val: " << head->val << "\nhead->next: " << head->next << std::endl;
    for(int i = 1; i < 10; i++)
        singleLinkListAdd(head, i);
    printLinkList(head);
    deleteLinkList(head);
}

int main()
{
    testSingleLinkList();
    return 0;
}
