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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * head = new ListNode(0);
        ListNode * root = head;
        
        while(l1!= NULL && l2 != NULL){
            if(l1->val > l2->val){
                root->next = new ListNode(l2->val);
                l2 = l2->next;
                
            }
            else{
                root->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            root = root->next;
        }
        
        while(l1 != NULL){
            root->next = new ListNode(l1->val);
            l1 = l1->next;
            root = root->next;        
        }
        while(l2 != NULL){
            root->next = new ListNode(l2->val);
            l2 = l2->next;
            root = root->next;        
        }
        
        return head->next;
        
        
    }
};
