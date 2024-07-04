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
    ListNode* mergeNodes(ListNode* head) {
        if(!head || !head->next) return NULL;
        ListNode* head2 = new ListNode(0);
        ListNode* temp =  head->next;
        ListNode* temp2 = head2;
        long long sum = 0;
        
        temp2 = head2;
        while(temp) {
            // cout<<temp->val<<" ";
            if(!temp->val) {                
                ListNode* newnode = new ListNode(sum);
                
                temp2->next = newnode;
                
                temp2 = temp2->next;
                // cout<<temp2->val<<" ";
                sum = 0;
            }
            sum += temp->val;
            temp = temp->next;
        }
       
        head2 = head2->next;
        return head2;
    }
};