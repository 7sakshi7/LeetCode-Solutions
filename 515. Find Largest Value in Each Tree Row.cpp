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
    void traverse(TreeNode* root,map<int,int>&m,int curr){
        if(root == NULL)
            return;
        
        if(m.find(curr)!=m.end()){
            m[curr] = max(m[curr],root->val);
        }
        else
            m[curr] = root->val;
       
        traverse(root->left,m,curr+1);
        traverse(root->right,m,curr+1);
    }
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL)
            return {};
        map<int,int>m;
        traverse(root,m,0);
        vector<int>v;
        for(auto it : m)
            v.push_back(it.second);
        
        return v;
    }
};
