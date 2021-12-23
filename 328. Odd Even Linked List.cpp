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
        ListNode *oS = NULL, *oE = NULL, *eS =NULL, *eE = NULL;
        
        ListNode* temp = head;
        int index = 1;
        while(temp!=NULL){
            if((index)%2 == 0){
                if(eS == NULL){
                    eS = temp;
                    eE = eS;
                }
                else{
                    eE->next = temp;
                    eE = temp;
                }
            }
            else{
               if(oS == NULL){
                    oS = temp;
                    oE = oS;
                }
                else{
                    oE->next = temp;
                    oE = temp;
                } 
            }
            
            temp = temp->next;
            index++;
        }
        
        if(eS==NULL)return oS;
        if(oS == NULL)return eS;
        
        oE->next = eS;
        eE->next = NULL;
        temp = oS;
        return oS;
    }
};
