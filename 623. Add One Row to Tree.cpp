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
    void findDepthRoot(TreeNode* root,vector<TreeNode*>&depthRoot,int depth,int currDepth){
        if(root == NULL)
            return;
        
        if(currDepth == depth){
            depthRoot.push_back(root);         
        }
        
        findDepthRoot(root->left,depthRoot,depth,currDepth+1);
        findDepthRoot(root->right,depthRoot,depth,currDepth+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        vector<TreeNode*>depthRoot;
        findDepthRoot(root,depthRoot,depth-1,1);
        
        for(int i = 0;i<depthRoot.size();i++){
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);

            leftNode->left = depthRoot[i]->left;
            rightNode->right = depthRoot[i]->right;

            depthRoot[i]->left = leftNode;
            depthRoot[i]->right = rightNode;
        }  
        return root;
        
    }
};
