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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sortedList = head;
        ListNode* unSortedList = head->next;
        
        if(head == NULL || head->next== NULL)return head;
        
        ListNode* sortedTail = head;
        
        while(unSortedList!=NULL){
            ListNode* sortedPrev = NULL;
            cout<<unSortedList->val<<endl;
            while(sortedList->val<=unSortedList->val && sortedList!=unSortedList){
                
                sortedPrev = sortedList;
                sortedList=sortedList->next;
                // cout<<"Entered in while loop "<<sortedList->val<<" "<<sortedPrev->val<<endl;
            }
            
            if(sortedList == unSortedList){
                sortedTail = sortedList;
                unSortedList = unSortedList->next;
            }
            
            else if(sortedList->val > unSortedList->val){
                ListNode* node = unSortedList->next;
                if(sortedPrev == NULL){
                    sortedTail->next = unSortedList->next;
                    unSortedList->next = head;   
                    head = unSortedList;
                    unSortedList = node;
                }
                else{
                    unSortedList->next = sortedPrev->next;
                    sortedPrev->next = unSortedList;
                   sortedTail->next = node;
                    unSortedList = node;
                }
            }
            
            sortedList = head;
        }
        return head; 
    }
};
