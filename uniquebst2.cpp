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
    
    vector<TreeNode *> test(int left,int right){
        
        vector<TreeNode *> result;
        if(left > right){
            result.push_back(NULL);
            return result;
        }
        if(left == right){
            TreeNode * tree = new TreeNode(left);
            result.push_back(tree);
            return result;
        }
        
        for(int i = left; i <= right; i ++){
            vector<TreeNode *> lefttree = test(left, i -1);
            vector<TreeNode *> righttree = test(i+1,right);
            
            for(int j = 0; j < lefttree.size(); j ++){
                for(int k = 0; k < righttree.size(); k ++){
                    TreeNode * now = new TreeNode(i);
                    now->left = lefttree[j];
                    now->right = righttree[k];
                    result.push_back(now);
                }
            }
            
        }
        return result;
        
        
    }
    
    
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return test(1,n);

    }
};
