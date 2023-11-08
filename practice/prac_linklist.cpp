#include <bits/stdc++.h>
#include <cstdlib>

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

Node* randomGenarateListNode()
{
    Node *dummy = new Node(-1);
    Node *node = dummy;
    int sz = std::min(std::rand(), 20);
    for(int i = 0; i < sz; i++)
    {
        node->next = new Node(std::rand()%20);
        node = node->next;
    }
    node = dummy->next;
    delete dummy;
    return node;
}

Node* reverseListSome(Node *head, int l, int r)
{

}

int getLinkListLength(Node *head)
{
    if(head==nullptr)
        return 0;
    return 1+getLinkListLength(head->next);
}

void testLinkList()
{
    std::cout << "Test single link list" << std::endl;
    Node *head = randomGenarateListNode();
    printLinkList(head);
    std::cout << "删除第二个节点" << std::endl;
    removeNode(head, head->next);
    printLinkList(head);
    std::cout << "反转链表" << std::endl;
    head = reverse(head);
    printLinkList(head);
    std::cout << "反转链表" << std::endl;
    head = reverseV2(head);
    printLinkList(head);
    deleteLinkList(head);
    int sz = getLinkListLength(head);
    
}

int main()
{
    testLinkList();
    return 0;
}
