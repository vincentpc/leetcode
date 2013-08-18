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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * pre = new ListNode(0);
        ListNode * save = pre;
        pre->next = head;
        
        if(head == NULL)
            return head;
        
        ListNode * left,*right,*next;
        
        left = head;
        right = head->next;
        
        while(left != NULL && right != NULL){
            pre->next = right;
            left->next = right->next;
            right->next = left;
            
            pre = left;
            left = left->next;
            if(left == NULL)
                break;
            right = left->next;
            
        }
        
        return save->next;
    }
};
