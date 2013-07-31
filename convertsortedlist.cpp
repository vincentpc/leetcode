/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    vector<int> array;
    
    TreeNode * test(int begin, int end){
        
        TreeNode * root = new TreeNode(0);
        int mid = (begin+end)/2;
        root->val = array[mid];
        if(mid - 1 >= begin){
            root->left = test(begin,mid-1);
        }
        if(mid + 1 <= end){
            root->right = test(mid+1,end);
        }
        
        return root;
        
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //array = num;
        TreeNode * root = NULL;
        if(num.size() == 0)
            return root;
            
        root = test(0,num.size()-1);
        
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() 
        array.clear();
        while(head != NULL){
            array.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(array);
        
    }
};
