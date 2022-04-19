/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrder(vector<int>&v,TreeNode* root){
        if(root==NULL)
            return;
        
        inOrder(v,root->left);
        v.push_back(root->val);
        inOrder(v,root->right);
    }
    void changeNodes(TreeNode* root,unordered_map<int,int>&m){
        if(root == NULL)
            return;
        
        root->val = m[root->val];
        changeNodes(root->left,m);
        changeNodes(root->right,m);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>v;
        inOrder(v,root);
        
        int sum = 0;
        unordered_map<int,int>m;
        for(int i = v.size()-1;i>=0;i--){
            sum+=v[i];
            m[v[i]] = sum;
        }
        changeNodes(root,m);
        return root;
        
    }
};
