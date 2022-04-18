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
    void findPathSum(TreeNode* root,int targetSum,int sum,vector<int>temp,vector<vector<int>>&res){
        if(root == NULL)
            return;
        
        sum+=root->val;
        temp.push_back(root->val);
        
        if(targetSum == sum && root->left == NULL && root->right == NULL){
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        
        findPathSum(root->left,targetSum,sum,temp,res);
        findPathSum(root->right,targetSum,sum,temp,res);
        sum-=root->val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>temp;
        findPathSum(root,targetSum,0,temp,res);
        return res;
    }
};
