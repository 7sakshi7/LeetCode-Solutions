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
    void sumAllLeaf(TreeNode* root,int &sum,string &str){
        if(root==NULL)
            return;
        
        char ch = root->val+'0';
        str.push_back(ch);
        
        if(root->left == NULL && root->right == NULL){
            int x = 0;
            for(int i=0;i<str.size();i++){
                if(str[i] == '1'){
                   x = x| 1; 
                }
                x = x<<1;
            }
            x = x>>1;
            sum+=x;
            cout<<sum<<endl;
            str.pop_back();
            return;
        }
        
        sumAllLeaf(root->left,sum,str);      
        sumAllLeaf(root->right,sum,str);
        str.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        string str= "";
        int sum = 0;
        sumAllLeaf(root,sum,str);
        return sum;
    }
};
