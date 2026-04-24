/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 
 //Floyd’s Cycle-Finding Algorithm,
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * fast =head;
        ListNode * slow=head;


        while(fast!=nullptr && fast->next!=nullptr){

            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;//detected cycle
        }

return false;
    }
};