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
        ListNode * result = head;
        if(head == NULL)
            return result;
        
        int tag = result->val;
        ListNode * pre = result;
        head = head->next;
        
        while(head != NULL){
            if(head ->val == tag){
  
            }
            else{
                pre->next = head;
                tag = head->val;
                pre = pre->next;
                
            }
            head = head->next;
            
        }
        pre->next = NULL;
        
        return result;
        
    }
};
