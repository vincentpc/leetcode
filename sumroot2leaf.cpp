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
    int count;
    void test(TreeNode * root, int sum){
        if(root ->left == NULL && root->right == NULL){
            count += sum*10 + root->val;
            return;
        }
        
        if(root->left != NULL)
            test(root->left,sum*10+root->val);
        if(root->right != NULL)
            test(root->right,sum*10+root->val);
            
    }
    
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        count = 0;
        if(root == NULL){
            return count;
        }
        test(root,0);
        return count;
    }
};
