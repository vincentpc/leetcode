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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * pre = new ListNode(0);
        ListNode * left ;
        ListNode * leftsave;
        ListNode * rightsave;
        ListNode * right ;
        ListNode * root = head;
        
        if(m == n)
            return head;
        
        int i = 1;
        while(i <= n){
            if(i == m-1){
                pre = root;
            }
            else if(i == m){
                left = root;
            }
            else if(i == n){
                right = root;
                break;
            }
            
            i++;
            root = root->next;
        }
        
        leftsave = left;
        rightsave = right->next;
        
        pre->next = right;
        
        ListNode * leftnext = left->next;
        
        ListNode * temp;
        
        i = n-m;
        while(i > 0){
            if(leftnext != NULL)
                temp = leftnext->next;
            
            leftnext->next = left;
            left = leftnext;
            leftnext = temp;
            i--;
        }
        
        
        leftsave->next = rightsave;
        
        if(m == 1){
            return pre->next;
        }
        else return head;
        
    }
};
