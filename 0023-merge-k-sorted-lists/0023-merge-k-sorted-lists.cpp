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

 struct compare{
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }



 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
priority_queue<ListNode*,vector<ListNode*>,compare>minheap;

for(ListNode* head:lists){
 if(head)
    minheap.push(head);
}
ListNode* dummy=new ListNode(0);
ListNode* tail=dummy;

while(!minheap.empty()){
ListNode* curr=minheap.top();
minheap.pop();


tail->next=curr;
tail=tail->next;

if(curr->next){
    minheap.push(curr->next);
}




}


return dummy->next;

    }
};