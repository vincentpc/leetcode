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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * pre = head;
        ListNode * root = head;
        
        for(int i = 0; i < n; i ++){
            root = root->next;
        }
        
        if(root == NULL){
            return head->next;
        }
        while(root->next != NULL){
            pre = pre->next;
            root = root->next;
        }
        
        pre->next = pre->next->next;
        return head;
        
    }
};
