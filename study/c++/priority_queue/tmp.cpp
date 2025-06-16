#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node * next;
};

int getRandInt() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    //usage: x = dis(gen)
    return dis(gen);
}

void quickSort(vector<int> & arr, int l, int r) {
    if (l>=r) return;
    int ll = l, rr = r;
    int f = arr[ll];
    while (ll < rr) {
        while (ll < rr && arr[rr]>f) rr--;
        arr[ll] = arr[rr];
        while (ll < rr && arr[ll]<=f) ll++;
        arr[rr] = arr[ll];
    }
    arr[ll] = f;
    quickSort(arr, l, ll-1);
    quickSort(arr, ll+1, r);
}

Node * sort(Node * node1, Node * node2) {
    vector<int> arr;
    while(node1) {
        arr.push_back(node1->val);
        node1 = node1->next;
    }
    while(node2) {
        arr.push_back(node2->val);
        node2 = node2->next;
    }
    
    quickSort(arr, 0, arr.size()-1);
    Node * dummy = new Node(-1, nullptr);
    Node * p = dummy;
    for (auto & v:arr) {
        p->next = new Node(v, nullptr);
        p = p->next;
    }
    cout << arr.size() << endl;
    return dummy->next;
}

void print(Node * node, string prefix) {
    cout << prefix;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    Node * node1 = new Node(-1, nullptr);
    Node * node2 = new Node(-1, nullptr);
    map<int, Node*> mp;
    Node * p = node1;
    for (int i = 0; i < 10; i++) {
        Node * node = new Node(getRandInt(), nullptr);
        p->next = node;
        p = p->next;
    }
    p = node2;
    for (int i = 0; i < 10; i++) {
        Node * node = new Node(getRandInt(), nullptr);
        p->next = node;
        p = p->next;
    }
    print(node1, "node1: ");
    print(node2, "node2: ");
    Node * res = sort(node1, node2);
    print(res, "sort: ");
    return 0;
}