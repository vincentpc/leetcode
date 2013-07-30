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
    struct ele{
        TreeNode *node;
        int depth;
    };
    
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> >results;
        vector<int> result;
        queue<ele> q;
        int depthnow;
        
        if(root == NULL)
            return results;
        
        ele rootele;
        rootele.node = root;
        rootele.depth = 0;
        depthnow = 0;
        q.push(rootele);
        
        while(!q.empty()){
            ele nownode = q.front();
            q.pop();
            
            if(nownode.depth == depthnow){
                result.push_back(nownode.node->val);
            }
            else{
                results.push_back(result);
                result.clear();
                result.push_back(nownode.node->val);
                depthnow = nownode.depth;
            }
            
            if(nownode.node->left != NULL){
                ele leftele;
                leftele.node = nownode.node->left;
                leftele.depth = nownode.depth+1;
                q.push(leftele);
            }
            if(nownode.node->right != NULL){
                ele rightele;
                rightele.node = nownode.node->right;
                rightele.depth = nownode.depth+1;
                q.push(rightele);
            }
        }
        
        if(result.size() > 0)
            results.push_back(result);
        reverse(results.begin(),results.end());
        
        return results;
    
    }
};
