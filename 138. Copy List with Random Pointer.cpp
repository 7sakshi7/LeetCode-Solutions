/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return head;

       vector<Node*>v,res;
        int count = 1;
        Node* start = head->next;
        Node* newHead = new Node(head->val);
        Node* tail = newHead;
        head->val = INT_MAX-count;
        v.push_back(head->random);
        res.push_back(newHead);
        
        while(start!=NULL){
            tail->next = new Node(start->val);
            tail = tail->next;
            res.push_back(tail);
            count++;
            v.push_back(start->random);
            start->val = INT_MAX - count;
            start = start->next;
        }
        for(int i = 0;i<v.size();i++){
           if(v[i] == NULL)
               continue;
            int count = INT_MAX - v[i]->val;
            res[i]->random = res[count-1];
        }
        return newHead;
    }
};
