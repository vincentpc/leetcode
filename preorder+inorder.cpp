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
    TreeNode *root;
    vector<int> pre,in;
    
    TreeNode * createTree(int prebeg,int preend,int inbeg,int inend){
        
        if(prebeg > preend)
            return NULL;
        

        int rootval = pre[prebeg];
        TreeNode * root = new TreeNode(rootval);
        
        if(prebeg == preend){
            return root;
        }
        
        TreeNode * left = NULL;
        TreeNode * right = NULL;
        
        
        for(int i = inbeg;i <= inend; i ++){
            if(rootval == in[i]){
                int gap = i -1 - inbeg;
                
                left = createTree(prebeg+1,prebeg+gap+1,inbeg,i-1);
                right = createTree(prebeg+gap+2,preend,i+1,inend);
                break;        
            }
        }
        
        root->left = left;
        root->right = right;
        
        return root;
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        root = NULL;
        if(preorder.size() == 0)
            return root;
        
        pre = preorder;
        in = inorder;
        
        root = createTree(0,preorder.size()-1,0,inorder.size() - 1);
        
        return root;
        
    }
};
