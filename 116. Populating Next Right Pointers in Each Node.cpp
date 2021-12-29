/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)return NULL;
        
        queue<pair<int,Node*>>q,nextPointers;
        q.push({0,root});
        nextPointers.push({0,root});
        
        while(!q.empty()){
            if(q.front().second->left){
                q.push({q.front().first+1,q.front().second->left});
                nextPointers.push({q.front().first+1,q.front().second->left});
            }
            
            if(q.front().second->right){
                q.push({q.front().first+1,q.front().second->right});
                nextPointers.push({q.front().first+1,q.front().second->right});
            }
            q.pop();
        }
        
        while(!nextPointers.empty()){
            pair<int,Node*>p = nextPointers.front();
            nextPointers.pop();
            
            if(nextPointers.empty() || nextPointers.front().first!=p.first){
                p.second->next = NULL;
            }
            else{
                p.second->next = nextPointers.front().second;
            }
        }
        
        return root;
    }
};
