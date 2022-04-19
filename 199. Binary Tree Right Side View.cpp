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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        
        vector<int>v;
        int lastVal = -1;
        while(!q.empty()){
            pair<TreeNode*,int> temp = q.front();
            q.pop();
            
            if(temp.second!=lastVal){
                lastVal = temp.second;
                v.push_back(temp.first->val);
            }
            
            if(temp.first->right){
                q.push({temp.first->right,temp.second+1});
            }
            
             if(temp.first->left){
                q.push({temp.first->left,temp.second+1});
            }
        }
        return v;
    }
};
