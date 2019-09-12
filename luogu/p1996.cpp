#include<bits/stdc++.h>
using namespace std;
typedef struct Node {
    int val;
    Node* next;
}node;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int m, n;
    cin >> m >> n;
    node *head = NULL;
    node *last = NULL;
    for(int i = 1; i <= m; i++) {
        node *tmp = new node;
        tmp->val = i; tmp->next = NULL;
        if(head == NULL) {head = tmp;last = head;}
        else {last->next = tmp; last = tmp;}
    }
    if(last != NULL) last->next = head;
    node *front = last, *cur = head;
    while(front != cur)
    {
        int t = n-1;
        while(t-- > 0) {front = cur; cur = cur->next;}
        cout << cur->val << " ";
        cur = cur->next;
        delete front->next;
        front->next = cur;
    }
    if(cur != NULL) cout << cur->val << endl;
    return 0;
}
