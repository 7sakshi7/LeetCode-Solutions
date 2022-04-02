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
    bool sumEqualsTargetSum(TreeNode* root,int targetSum,int sum){
        if(root==NULL)
            return false;
        
        if(!root->left && !root->right){
             sum+=root->val;
            if(sum == targetSum)
                return true;
            else
                return false;
        }
        
        return sumEqualsTargetSum(root->left,targetSum,sum+root->val) || sumEqualsTargetSum(root->right,targetSum,sum+root->val);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return sumEqualsTargetSum(root,targetSum,0);
    }
};
