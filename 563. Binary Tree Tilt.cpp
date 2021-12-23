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
    int postOrder(TreeNode* root,int &sum){
        if(root==NULL)return 0;
        
        if(root->left == NULL && root->right==NULL)return root->val;
        
        if(root->left == NULL){
            int x = postOrder(root->right,sum);
            sum+=abs(0-x);
            return x+root->val;
        }
        
        if(root->right == NULL){
            int x = postOrder(root->left,sum);
            sum+=abs(0-x);
            return x+root->val;
        }
            
        int x = postOrder(root->left,sum);
        int y = postOrder(root->right,sum);
        sum+=abs(x-y);
        return (x+y)+root->val;
    }
    int findTilt(TreeNode* root) {
        int sum = 0;
         postOrder(root,sum);
        return sum;
    }
};
