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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode* curr=head;
        int length=0;
        while(curr!=nullptr){
            length++;
            curr=curr->next;
        }
        k=k%length;
        if(k==0) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode*temp;

        while(k>0){
            fast=fast->next;
            k--;
        }

        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        temp=slow->next;
        slow->next=nullptr;
        fast->next=head;
        head=temp;

        return head;
    }
};