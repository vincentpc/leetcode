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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * savehead;
        ListNode * root;
        ListNode * pre;
        
        if(head == NULL)
            return head;
            
        int n = 0;
        root = head;
        while(root!= NULL){
            n++;
            root = root->next;
        }
        
        k = k % n;
        
        if(k == 0)
            return head;
            
        root = head;
        for(int i = 0; i < k; i ++){
            root = root->next;
            
        }
        pre = head;
        
        while(root->next != NULL){
            pre = pre->next;
            root = root->next;
        }
        
        savehead = pre->next;
        pre->next = NULL;
        root->next = head;
        
        return savehead;
    }
};
