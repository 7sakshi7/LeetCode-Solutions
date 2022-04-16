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
    TreeNode* buildBinaryTree(vector<int>&pre,vector<int>&in,int l,int r,int &index){
        if(l>r || index>in.size()-1)
            return NULL;
        
        int i = mp[pre[index]];
        
        if(i<l || i>r)
            return NULL;
        
        TreeNode* newNode = new TreeNode(pre[index]);
        index++;
        newNode->left = buildBinaryTree(pre,in,l,i-1,index);
        newNode->right = buildBinaryTree(pre,in,i+1,r,index);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i<inorder.size();i++)
            mp[inorder[i]] = i;
        
        int index = 0;
        return buildBinaryTree(preorder,inorder,0,inorder.size()-1,index);
    }
};
