/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

    void test(TreeLinkNode *root){
        if(root == NULL)
            return;
        
        if(root->left!= NULL){
            if(root->right!= NULL)
                root->left->next = root->right;
            else if(root->next != NULL){
                if(root->next->left != NULL)
                    root->left->next = root->next->left;
                else if(root->next->right != NULL)
                    root->left->next = root->next->right;
                
            }
        }
        
        if(root->right != NULL){
            if(root->next != NULL){
                if(root->next->left != NULL)
                    root->right->next = root->next->left;
                else if(root->next->right != NULL)
                    root->right->next = root->next->right;
                
            }            
        }
        
        if(root->left != NULL)
            test(root->left);
            
        if(root->right != NULL)
            test(root->right);
     
        return;
        
    }
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        test(root);
    }
};
