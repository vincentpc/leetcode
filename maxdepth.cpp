/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int depth;
    
    void dfs(TreeNode * root, int dep){
        if(root->left == NULL && root->right == NULL){
            if(depth < dep)
                depth = dep;
            return;
        }
        if(root->left != NULL)
            dfs(root->left,dep+1);
        
        if(root->right != NULL)
            dfs(root->right,dep+1);
        return;
        
    }
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        depth = 0;
        if(root == NULL)
            return depth;
        dfs(root,1);
        
        return depth;
    }
};
