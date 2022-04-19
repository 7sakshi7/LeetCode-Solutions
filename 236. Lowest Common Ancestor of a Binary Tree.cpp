/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root,vector<TreeNode*>&v,TreeNode* ele,bool &found){
        if(root == NULL)
            return;
        
        v.push_back(root);
        if(root== ele){
            found = true;
             return; 
        }
        bool p=0,q=0;
        traverse(root->left,v,ele,found);
        traverse(root->right,v,ele,found);
        
        if(!found){
            v.pop_back();
        }
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>pNodes,qNodes;
        bool f = 0;
        traverse(root,pNodes,p,f);
        f = 0;
        traverse(root,qNodes,q,f);
        
        int m;
        if(pNodes.size()<qNodes.size()){
            m = pNodes.size()-1;
        }
        else
            m = qNodes.size()-1;
        
        while(m>=0){
            if(pNodes[m] == qNodes[m])
                return pNodes[m];
            m--;
        }
        return NULL;  
    }
};
