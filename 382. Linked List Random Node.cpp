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

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
