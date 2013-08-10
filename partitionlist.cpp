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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a[1000];
        ListNode * savehead = head;
        int i = 0, j = 0;
        while(head != NULL){
            a[i] = head->val;
            head = head->next;
            i++;    
        }
        
        int n = i;
        for(i = 0; i < n; i ++){
            if(a[i] >= x)
                continue;
            int tag = a[i];
            for(j = i-1; j >= 0; j --){
                if(a[j] >= x){
                    a[j+1] = a[j];
                }
                else{
                    
                    break;
                }
            }
            a[j+1] = tag;
        }
        
        ListNode * root = savehead;
        i = 0;
        while(root!= NULL){
            root->val = a[i];
            i++;
            root = root->next;
        }
        return savehead;
        
    }
};
