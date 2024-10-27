#include <bits/stdc++.h>
#include <unordered_map>

struct Node 
{
    Node * prev;
    Node * next;
    int key;
    int val;
    Node(int key_, int val_): key(key_), val(val_)
    {
        prev = next = nullptr;
    }
};



class LRU 
{
public:
    LRU(int sz_): sz(sz_) {}

    void put(int key, int val)
    {

    }

    int get(int key)
    {
        return 0;
    }

private:
    Node * head;
    Node * tail;
    std::unordered_map<int, Node*> idx;
    int sz;
};

int main()
{
    return 0;
}