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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        string str = "";
        while(temp!=NULL){
            str.push_back((temp->val)+'0');
            temp = temp->next;
        }
        
        int power = 1,ans = 0;
        
        for(int i = str.size()-1;i>=0;i--){
            ans+=power*(str[i]-'0');
            power *= 2;
        }
        return ans;
    }
};

// 100% faster
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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head->next;
        int ans;
        if(head->val)
            ans = 1;
        else
            ans = 0;
        while(temp!=NULL){
            ans = ans<<1;
            if(1&(temp->val)){
                ans = ans | 1;
            }
            temp = temp->next;
        }
        return ans;
    }
};
