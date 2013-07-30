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
    vector<int> result;
    void inorder(TreeNode * root){
        if(root -> left != NULL)
            inorder(root->left);
        result.push_back(root->val);
        if(root->right != NULL)
            inorder(root->right);
        return;
        
    }
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //result.clear();
        
        if(root == NULL)
            return result;
        inorder(root);
        return result;
        
    }
};
