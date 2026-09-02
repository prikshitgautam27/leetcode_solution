/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       // approach is to find the middle of thr link list 
       // then to satrt reversing the middle ->next element and then to 
       // comarent the values of the element of list

        ListNode* fast=head;
        ListNode* slow=head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;

        }

        ListNode* prev=nullptr;
        ListNode* curr=slow;

        while(curr!=nullptr){
            ListNode* nextnode=curr->next;
            curr->next=prev;

            prev=curr;
            curr=nextnode;
        }
        
        ListNode* l1=head;
        ListNode* l2=prev;

        while(l1!=nullptr && l2!=nullptr){
            if(l1->val!=l2->val){
                return false;
            }
           l1=l1->next;
           l2=l2->next;
        }
        return true;
    }
};