#include <bits/stdc++.h>

typedef struct InternalNode
{
    InternalNode *pre;
    InternalNode *next;
    int val;
    InternalNode(int val_): val(val_) {}
}Node;

Node* singleLinkListAdd(Node *head, int v)
{
    if(head == nullptr)
    {
        head = new Node(v);
        return head;
    }
    Node *ori_head = head;
    while(head->next != nullptr)
    {
        head = head->next;
    }
    head->next = new Node(v);
    return ori_head;
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

Node* reverse(Node *head)
{
    if(head==nullptr||head->next==nullptr) return head;
    Node *pre = head;
    head = head->next;
    pre->next = nullptr;
    while(head!=nullptr)
    {
        Node *next_node = head->next;
        head->next = pre;
        pre = head;
        head = next_node;
    }
    return pre;
}

Node* reverseV2(Node *node)
{
    if(node==nullptr||node->next==nullptr)
        return node;
    Node *last_node = reverseV2(node->next);
    node->next->next = node;
    node->next = nullptr;
    return last_node;
}

void testLinkList()
{
    std::cout << "Test single link list" << std::endl;
    Node *head = nullptr;
    for(int i = 1; i < 10; i++)
        head = singleLinkListAdd(head, i);
    removeNode(head, head->next);
    printLinkList(head);
    head = reverse(head);
    printLinkList(head);
    head = reverseV2(head);
    printLinkList(head);
    deleteLinkList(head);
}

int main()
{
    testLinkList();
    return 0;
}
