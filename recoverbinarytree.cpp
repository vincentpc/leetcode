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
    TreeNode * left,*right;
    TreeNode * pre;
    
    void test(TreeNode * root){
        
        
        if(root == NULL)
            return ;
            
        test(root->left);
        if(pre != NULL){
            if(pre->val > root->val){
                if(left == NULL){
                    left = pre;
                    right = root;
                }
                else{
                    right = root;
                }
            }
            
        }
        
        pre = root;

        test(root->right);
        
        
    }
    
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return;
        left = right = NULL;
        pre = NULL;
        test(root);
        swap(left->val,right->val);
        
        return;
    }
};
