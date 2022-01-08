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
    int pairSum(ListNode* head) {
        if(head == NULL || head->next ==NULL)return 0;
        vector<int>v;
        while(head!=NULL){
            v.push_back(head->val);
            head = head->next;
        }
        
        int i = 0,j = v.size()-1;
        int sum = INT_MIN;
        while(i<j){
            sum = max(sum,(v[i]+v[j]));
            i++;
            j--;
        }
        return sum;
    }
};
