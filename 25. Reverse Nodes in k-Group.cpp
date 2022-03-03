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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev = NULL,*curr = head,*next = NULL;
        int count = k;
        while(count-- > 0 && curr!=NULL){
            curr = curr->next;
        }
        if(count!=-1){
            return head;
        }
        count = k;
        curr = head;
        while(count-->0 && curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode *newHead = prev;
        if(next!=NULL){
            head->next = reverseKGroup(next,k);
        }
        return newHead;
    }
};
