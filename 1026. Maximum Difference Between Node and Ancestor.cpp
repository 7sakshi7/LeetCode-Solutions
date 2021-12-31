// 100% faster
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
    pair<int,int> dfs(TreeNode*root,int &maxDiff){
        if(root == NULL)
            return {INT_MAX,INT_MIN};
        
        if(root->left == NULL && root->right == NULL){
            return {root->val,root->val};
        }
                
        pair<int,int> x = dfs(root->left,maxDiff);
        pair<int,int> y = dfs(root->right,maxDiff);
        
        maxDiff = max(maxDiff,abs(root->val-min(x.first,y.first)));
        maxDiff = max(maxDiff,abs(root->val-max(x.second,y.second)));
        return{ min(x.first,min(y.first,root->val)),max(max(x.second,y.second),root->val)};
    }
   
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = -1;
        dfs(root,maxDiff);
        return maxDiff;
    }
};
