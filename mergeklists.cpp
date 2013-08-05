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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * head = new ListNode(0);
        ListNode * root = head;
        
        while(1){
            int flag = 0;
            int mini = 1000000;
            int now;
            
            for(int i = 0; i < lists.size(); i ++){

                if(lists[i] != NULL && lists[i]->val < mini){
                    now = i;
                    mini = lists[i]->val;
                    flag = 1;
                }
            }
            
            if(flag == 0)
                break;
            else{
                root->next = new ListNode(mini);
                root = root->next;
                lists[now] = lists[now]->next;
            }
        }
        return head->next;
    }
};
