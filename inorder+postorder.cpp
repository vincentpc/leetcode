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
    vector<int> post,in;
    
    TreeNode * createTree(int postbeg,int postend,int inbeg,int inend){
        
        if(postbeg > postend)
            return NULL;
        

        int rootval = post[postend];
        TreeNode * root = new TreeNode(rootval);
        
        if(postbeg == postend){
            return root;
        }
        
        TreeNode * left = NULL;
        TreeNode * right = NULL;
        
        
        for(int i = inbeg;i <= inend; i ++){
            if(rootval == in[i]){
                int gap = i -1 - inbeg;
                
                left = createTree(postbeg, postbeg+gap,inbeg,i-1);
                right = createTree(postbeg+gap+1 ,postend-1,i+1,inend);
                break;        
            }
        }
        
        root->left = left;
        root->right = right;
        
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        root = NULL;
        if(inorder.size() == 0)
            return root;
        
        post = postorder;
        in = inorder;
        
        root = createTree(0,postorder.size()-1,0,inorder.size() - 1);
        
        return root;
        
    }
};
