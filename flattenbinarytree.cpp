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

    TreeNode * test(TreeNode *root){
        TreeNode * left = NULL, * rightbranch = NULL;
        TreeNode * saveright = root->right;
        

        if(root->left!= NULL){
            left = test(root->left);
        }
        
        root->right = left;
        root->left = NULL;
        rightbranch = root;
        
        while(rightbranch->right != NULL)
            rightbranch = rightbranch->right;
        
        if(saveright!= NULL){
            rightbranch->right = test(saveright); 
        }
        else rightbranch->right = NULL;
        
            
        return root;
        
        
    }
    
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return;
            
        root = test(root);
        return;
    }
};
