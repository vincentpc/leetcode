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
    vector<int> tree;
    void test(TreeNode* root){
        if(root == NULL)
            return;
        
        test(root->left);
        tree.push_back(root->val);
        test(root->right);
    }
    
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        
        tree.clear();
        
        test(root);
        
        int i=0,j = tree.size() -1;
            
        while(i <= j){
            if(tree[i] != tree[j])
                return false;
            i++;
            j--;
        }
        
        
        return true;
    }
};
