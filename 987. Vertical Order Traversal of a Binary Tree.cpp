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
    void levelOrderTraversal(TreeNode* root,int count,int level,map<int,multiset<pair<int,int>>>&cols){
        if(root == NULL)
            return;
        
        cols[count].insert({level,root->val});
        levelOrderTraversal(root->left,count-1,level+1,cols);
        levelOrderTraversal(root->right,count+1,level+1,cols);
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int,multiset<pair<int,int>>>cols;      
       vector<vector<int>>res;
        
        levelOrderTraversal(root,0,0,cols);
        
        for(auto it : cols){
            vector<int>temp;
            for(auto itr : it.second){
                temp.push_back(itr.second);
            }
            res.push_back(temp);
        }
        return res;
    
    }
};
