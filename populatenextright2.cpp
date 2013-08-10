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
        TreeLinkNode * nextnode;
        

            

     
        if(root->left!= NULL){
            if(root->right!= NULL)
                root->left->next = root->right;
            else{
                nextnode = root->next;
                while(nextnode != NULL){
                    if(nextnode->left != NULL){
                        root->left->next = nextnode->left;
                        break;
                    }
                    
                    else if(nextnode->right != NULL){
                        root->left->next = nextnode->right;
                        break;
                    }
                    else{
                        nextnode = nextnode->next;
                    }
                }
                 
            }
        }
        
        if(root->right != NULL){
                nextnode = root->next;
                while(nextnode != NULL){
                    if(nextnode->left != NULL){
                        root->right->next = nextnode->left;
                        break;
                    }
                    
                    else if(nextnode->right != NULL){
                        root->right->next = nextnode->right;
                        break;
                    }
                    else{
                        nextnode = nextnode->next;
                    }
                }
                 
               
        }
        
        if(root->right != NULL)
            test(root->right);
        if(root->left != NULL)
            test(root->left);
        return;
        
    }
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        test(root);
    }
};
