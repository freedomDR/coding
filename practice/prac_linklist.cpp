#include <bits/stdc++.h>

typedef struct InternalNode
{
    InternalNode *pre;
    InternalNode *next;
    int val;
    InternalNode(int val_): val(val_) {}
}Node;

std::shared_ptr<Node> initSingleLinkList()
{
    auto head = std::make_shared<Node>(-1);
    return head;
}

void singleLinkList(std::shared_ptr<Node> head, int v)
{
    if(head == nullptr)
    {
        std::cerr << "head is nullptr" << std::endl;
        return;
    }
    auto tmp_head = head.get();
    while(tmp_head->next != nullptr)
    {
        std::cout << tmp_head->val << std::endl;
        tmp_head = tmp_head->next;
    }
    tmp_head->next = std::make_shared<Node>(v).get();
}

void testSingleLinkList()
{
    std::cout << "Test single link list" << std::endl;
    auto head = initSingleLinkList();
    std::cout << "head->val: " << head->val << "\nhead->next: " << head->next << std::endl;
    for(int i = 1; i < 10; i++)
    {
        singleLinkList(head, i);
        std::cout << "head->val: " << head->val << "\nhead->next: " << head->next << std::endl;
    }
}

int main()
{
    testSingleLinkList();
    return 0;
}
