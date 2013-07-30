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
    int maxSum;
    
    int test(TreeNode *root){
        int leftsum=0,rightsum = 0;
        
        if(root->left != NULL)
            leftsum = test(root->left);
        if(root->right != NULL)
            rightsum = test(root->right);
        
        if(leftsum < 0)
            leftsum = 0;
        if(rightsum < 0)
            rightsum = 0;
            
        if(leftsum + rightsum + root->val > maxSum)
            maxSum = leftsum+rightsum+root->val;
        

        return max(leftsum+root->val,rightsum+root->val);
        
        
        
    }
    
    
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        maxSum = -10000;
        if(root==NULL)
            return maxSum;
            
        test(root);
        
        return maxSum;
        
    }
};
