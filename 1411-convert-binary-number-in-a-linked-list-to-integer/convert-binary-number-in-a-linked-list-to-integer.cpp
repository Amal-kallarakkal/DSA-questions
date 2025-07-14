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
        int ans = 0, cnt = 0;
        while(temp != NULL) {
            temp = temp->next;
            cnt++;
        }
        cout<<cnt;
        temp = head;
        for(int i = 0; i < cnt; i++) {
            if(temp->val == 1) ans += pow(2,cnt -1 - i);
            temp = temp->next;
        }

        return ans;
    }
};