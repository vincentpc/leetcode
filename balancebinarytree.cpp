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
    int  test(TreeNode *root,int depth){
        int leftdepth = depth+1;
        int rightdepth = depth+1;
        
        if(root->left != NULL)
            leftdepth = test(root->left,depth+1);
        if(root->right != NULL)
            rightdepth = test(root->right,depth+1);
        
        if(abs(leftdepth-rightdepth) > 1)
            check = false;
        
        return max(leftdepth,rightdepth);
        
        
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        check = true;
        if(root == NULL)
            return check;
        test(root,0);
        return check;
    }
};
