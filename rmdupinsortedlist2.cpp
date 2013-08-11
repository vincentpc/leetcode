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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * result = new ListNode(0);
        if(head == NULL)
            return result->next;
        
        int tag = result->val;
        ListNode * pre = result;
        int count = 0;
        
        while(head != NULL){
            if(head ->val == tag){
                count++;
            }
            else{
                if(count == 1){
                    pre->next = new ListNode(tag);
                    pre = pre->next;
                }
                count = 1;
                tag = head->val;
                
                
            }
            head = head->next;
            
        }
        if(count == 1){
            pre->next = new ListNode(tag);
            pre = pre->next;
        }        
        
        return result->next;
        
    }
};
