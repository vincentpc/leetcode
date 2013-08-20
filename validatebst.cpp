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
    bool check;
    TreeNode * pre;
    TreeNode * test(TreeNode * root){
        if(root == NULL)
            return NULL;
            
        if(root->left != NULL){
            pre = test(root->left);

        }
        
        if(pre != NULL && pre->val >= root->val)
            check = false;
            
        pre = root;
        TreeNode * right = root;
        
        if(root->right != NULL){
            right = test(root->right);
        }
       
        return right;
        
    }
    
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        check = true;
        if(root == NULL)
            return check;
        pre = NULL;
        test(root);
        return check;
    }
};
