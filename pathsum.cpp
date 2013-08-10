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
    int findsum;
    bool check;
    
    void test(TreeNode * root, int count){
        
        if(count == findsum && root->left == NULL && root->right == NULL){
            check = true;
            return;
        }
        if(count > findsum){
            
        }
        
        if(root->left != NULL)
            test(root->left,count+root->left->val);
        if(root->right != NULL)
            test(root->right,count+root->right->val);
            
        return;
    }
    
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        findsum = sum;
        check = false;
        
        if(root == NULL){
            return check;
        }
        test(root,root->val);
        
        return check;
    }
};
