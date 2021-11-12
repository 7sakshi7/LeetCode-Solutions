class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return NULL;
        
        if(head->next==NULL){
            if(head->val==val)return NULL;
            else
                return head;
        }            
        ListNode* temp = head;
        if(head->val==val)
            head = head->next;
         
        while(temp!=NULL && temp->next!=NULL){
            cout<<temp->val<<" ";
            if(temp->next->val==val){
                if(head == temp->next){
                    head = temp->next->next;
                }
                temp->next = temp->next->next;                 
            }
            else
            temp=temp->next;
        }
        return head;
    }
};
