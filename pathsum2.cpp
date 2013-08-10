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
    vector<vector<int>> results;
    
    void test(TreeNode * root, int count,vector<int> res){
        
        if(count == findsum && root->left == NULL && root->right == NULL){
            results.push_back(res);
            return;
        }
        if(count > findsum){
            
        }
        
        if(root->left != NULL){
            res.push_back(root->left->val);
            test(root->left,count+root->left->val,res);
            res.pop_back();
        }
        
        if(root->right != NULL){
            res.push_back(root->right->val);
            test(root->right,count+root->right->val,res);
            res.pop_back();
        }
            
        return;
    }
    
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        findsum = sum;
        check = false;
        results.clear();
        
        if(root == NULL){
            return results;
        }
        vector<int> res;
        res.push_back(root->val);
        test(root,root->val,res);
        
        return results;
    }
};
