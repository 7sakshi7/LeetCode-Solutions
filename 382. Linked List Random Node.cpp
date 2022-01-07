class Solution {
public:
    
   vector<int>s;
    Solution(ListNode* head) {
         ListNode* start;
        start = head;
        
        while(start!=NULL){
            s.push_back(start->val);
            start = start->next;
        }
        
    }
    
    int getRandom() {
        int num = rand()%s.size();
        return s[num];
    }
};


// 2nd Approach Without Using Space

class Solution {
public:
    int count = 0;
    ListNode *start;
    Solution(ListNode* head) {
        start = head;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }  
    }
    
    int getRandom() {
        int num = rand()%count;
        ListNode* temp = start;
        while(num--){
            temp = temp->next;
        }
        return temp->val;
    }
};
