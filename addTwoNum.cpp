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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head;
        ListNode *result = new ListNode(0);
        head = result;
        
        int now=0,carry = 0;
        ListNode *left=l1,*right=l2;
        while(left != NULL || right != NULL){
            result->next = new ListNode(0);
            result = result->next;            
            
            if(left!= NULL && right != NULL){
                now += left->val + right->val;
                if(now >= 10){
                    result->val = now%10;
                    now/=10;
                    
                }
                else{
                    result->val = now;
                    now = 0;
                }
                left = left->next;
                right = right->next;
            
            }
            else if(left!= NULL){
                now += left->val;
                if(now >= 10){
                    result->val = now%10;
                    now/=10;
                    
                }
                else{
                    result->val = now;
                    now = 0;
                }
                left = left->next;
            
            }            
            else if(right != NULL){
                now += right->val;
                if(now >= 10){
                    result->val = now%10;
                    now/=10;
                    
                }
                else{
                    result->val = now;
                    now = 0;
                }
                right = right->next;
            
            }

            
        }
        
        if(now >0){
            result->next = new ListNode(now);
            result = result->next;     
        }

        return head->next;
        
        
    }
};
