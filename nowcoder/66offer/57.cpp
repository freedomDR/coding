/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL) return NULL;
        if(pNode->right != NULL) 
        {
            TreeLinkNode* node = pNode->right;
            while(node->left != NULL) node = node->left;
            return node;
        }
        while(pNode->next != NULL){
            if(pNode->next->left == pNode) return pNode->next;
            pNode = pNode->next;
        }
        return NULL;
    }
};
