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
    void reorderList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)return;
        vector<ListNode*>address;
        
        ListNode* temp = head;
        while(temp!=NULL){
            address.push_back(temp);
            temp = temp->next;
        }
        
        int index = address.size()-1,start = 0;
        temp = head;
        ListNode* tail = address[index];
        
        if(address.size()%2==0){
            while(start+1<index){
            temp->next = tail;
            tail->next = address[start+1];
            start++;
            index--;
            temp = address[start];
            tail = address[index];
            
            cout<<start<<index<<endl;
        }
            
            address[index]->next = NULL;
            temp = head;
        }
        
        else{
            while(start<index){
            temp->next = tail;
            tail->next = address[start+1];
            start++;
            index--;
            temp = address[start];
            tail = address[index];
            
            cout<<start<<index<<endl;
        }
        
        if(start == index){
            address[index]->next = NULL;
        } 
        } 
    }
};
