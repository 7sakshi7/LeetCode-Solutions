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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {  
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        int lastVal = 0;
        vector<int>temp;
        stack<TreeNode*>st1,st2;
        st1.push(root);
        
        
        while(!st1.empty() || !st2.empty()){
            while(!st1.empty()){
                temp.push_back(st1.top()->val);
                if(st1.top()->left){
                    st2.push(st1.top()->left);
                }
                if(st1.top()->right){
                    st2.push(st1.top()->right);
                }
                st1.pop();
            }
            if(!temp.empty())
            res.push_back(temp);
            temp.clear();
            
            while(!st2.empty()){
                temp.push_back(st2.top()->val);
                if(st2.top()->right){
                    st1.push(st2.top()->right);
                }
                if(st2.top()->left){
                    st1.push(st2.top()->left);
                }
                st2.pop();
            } 
            if(!temp.empty())
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};
