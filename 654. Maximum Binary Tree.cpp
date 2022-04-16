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
    unordered_map<int,int>mp;
    
    int findMaxEle(int l,int r,vector<int>&nums){
        int maxEle = INT_MIN;
        for(int i = l;i<=r;i++)
            maxEle = max(maxEle,nums[i]);        
        return maxEle;
    }
    
    TreeNode* buildTree(vector<int>&nums,int l,int r){
        if(l>r)
            return NULL;
        int maxEle = findMaxEle(l,r,nums);
        
        int index = mp[maxEle];
        if(index<l || index>r)
            return NULL;
        TreeNode* newNode = new TreeNode(maxEle);
        
        newNode->left = buildTree(nums,l,index-1);
        newNode->right = buildTree(nums,index+1,r);
        return newNode;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++)
            mp[nums[i]] = i;
        
        return buildTree(nums,0,nums.size()-1);
    }
};
