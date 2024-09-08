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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> list;
        ListNode* temp = head;
        int n = 0;
        while(temp) {
            n++;            
            temp = temp->next;
        }
        
        if(n < k) {
            int i = 0;     
            ListNode* temp;
            
            while(n--) {
                temp = head;
                list.push_back(head);
                head = temp->next;
                temp->next = NULL;
                k--;
            }
            
            while(k--) {
                list.push_back(NULL);
                
            }
            
        } else {
            float part;
            int i = 0;
            ListNode* temp;
            while(k) {
                temp = head;
                part = ceil(n*(1.0)/k);
                n -= part;
                list.push_back(head);
                
                i = 0;
                while(i < part - 1 && temp != NULL) {
                    temp = temp->next;
                    i++;
                }              

                head = temp->next;
                if(temp) temp->next = NULL;
                k--;
            }
        }

        return list;
    }
};