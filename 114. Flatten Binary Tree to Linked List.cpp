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
    void flatten(TreeNode* root) {
        if(root == NULL || (!root->left && !root->right))
            return;
        stack<TreeNode*>st;
        st.push(NULL);
        TreeNode* prev = root;
        while(!st.empty()){
            while(root!=NULL){
                if(root->right){
                    st.push(root->right);
                }
                root->right = root->left;
                prev = root; 
                TreeNode* t = root;
                root = root->left;
                t->left = NULL;                 
            }
            root = st.top();
            st.pop();
            prev->right = root;
        }
    }
};
