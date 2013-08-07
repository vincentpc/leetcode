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
    void dfs(TreeNode * root,int dep){
        if(root->left == NULL && root->right == NULL){
            if(dep < depth)
                depth = dep;
            return;
            
        }
        
        if(root->left != NULL)
            dfs(root->left,dep+1);
        
        if(root->right != NULL)
            dfs(root->right,dep+1);
            
        
    }
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        depth = 100000;
        if(root == NULL)
            return 0;
        dfs(root, 1);
        
        return depth;
        
    }
};
