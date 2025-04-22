#include <bits/stdc++.h>
#include <optional>
#include <unordered_map>
using namespace std;


struct Node {
    int val;
    int key;
    Node *pre;
    Node *nxt;
    // Node(int val_, int key_, Node * pre_, Node * nxt_): val(val_), key(key_), pre(pre_), nxt(nxt_) {}
};

// single thread
class LRU {
    public:
        LRU(int capacity_): capacity(capacity_), head(new Node(-1, -1, nullptr, nullptr)) {
            head->nxt = head;
            head->pre = head;
        }

        ~LRU() {
            delete head;
            for (auto & [k, v]:mp) {
                delete v;
            }
        }
        
        int get(int key) {
            if (!mp.contains(key)) return -1;
            remove(mp[key]);
            addNodeFirst(mp[key]);
            return mp[key]->val;
        }

        void push(int key, int val) {
            if (mp.contains(key)) {
                // update key
                mp[key]->val = val;
                updateNodePosition(mp[key]);
                return;
            }
            if (mp.size() == capacity) {
                Node * node = head->pre;
                remove(head->pre);
                mp.erase(node->key);
                destroyNode(node);
            }
            Node * node = new Node(val, key, nullptr, nullptr);
            mp[key] = node;
            addNodeFirst(node);
        }

        void print() {
            auto p = head->nxt;
            cout << "lru: ";
            while (p && p != head) {
                cout << p->val << " ";
                p = p->nxt;
            }
            cout << endl;
        }

    private:
        int capacity;
        unordered_map<int, Node*> mp;
        Node * head;
        
        void updateNodePosition(Node * node) {
            remove(node);
            addNodeFirst(node);
        }

        void remove(Node * node) {
            // node1 node2 node3
            node->pre->nxt = node->nxt;
            node->nxt->pre = node->pre;
        }

        void addNodeFirst(Node * node) {
            // head node1
            node->nxt = head->nxt;
            node->pre = head;
            head->nxt->pre = node;
            head->nxt = node;
        }

        void destroyNode(Node * node) {
            delete node;
        }
};

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    vector<int> arr = {};
    //usage: x = dis(gen)
    LRU lru(5);
    for (int i = 0; i < 20; i++) {
        arr.push_back(dis(gen));
    }

    for (auto & item : arr)
    {
        cout << item << " ";
        lru.push(item, item);
    }
    cout << endl;

    lru.print();
    cout << lru.get(dis(gen)) << endl;
    cout << lru.get(dis(gen)) << endl;
    cout << lru.get(dis(gen)) << endl;
    cout << lru.get(dis(gen)) << endl;
    lru.print();
    
    return 0;
}