/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * save = head;
        ListNode * pre = new ListNode(0);
        ListNode * left ;
        ListNode * leftsave;
        ListNode * rightsave;
        ListNode * right ;
        ListNode * root = head;
        
        
        if(k == 1)
            return head;
            
        for(int t = 0; ; t++){
            int i = 1;
            while(i <= k){
                if(root == NULL)
                    break;
                    
                if(i == 1){
                    left = root;
                }
                else if(i == k){
                    right = root;
                    break;
                }
                
                i++;
                root = root->next;
            }
            
            if(root == NULL)
                break;
            
        
            leftsave = left;
            rightsave = right->next;
            
            pre->next = right;
            
            ListNode * leftnext = left->next;
            
            ListNode * temp;
            
            i = k-1;
            while(i > 0){
                if(leftnext != NULL)
                    temp = leftnext->next;
                
                leftnext->next = left;
                left = leftnext;
                leftnext = temp;
                i--;
            }
            
            
            leftsave->next = rightsave;
            if(t == 0)
                save = pre->next;
            
            pre = leftsave;
            root = rightsave;

        
        }
        return save;
    }
};
