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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // min heap
        ios::sync_with_stdio(0);
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto x: lists) {
            ListNode* temp = x;
            while(temp) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        if(!pq.size()) return NULL;
        ListNode* head = new ListNode();        
        ListNode* temp = head;
        while(!pq.empty()) {                   
            temp->val = pq.top();
            pq.pop();  
            if(!pq.empty()) {
                ListNode* newNode = new ListNode(); 
                temp->next = newNode;
            }    
            temp = temp->next;           
        }

        return head;

    }
};