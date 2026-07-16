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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        if(head->next==nullptr){
            return head;
        }
        ListNode* even=head->next;
        ListNode* odd=head;
ListNode* evenhead=even;
        while(even!=nullptr && even->next!=nullptr){
            //making odd linked list
            odd->next=even->next;
            odd=odd->next;

                
                even->next=odd->next;
                even=even->next;
        }
        odd->next=evenhead;
        return head;

    }
};