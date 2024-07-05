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
 #pragma GCC optimize("OFast")
class Solution {
// ios::sync_with_stdio();
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        vector<int> ans(2, -1);
        if(!head) return ans;
        int a, b, c,i = 1;
        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* next = curr->next;

        if(next == NULL) return ans;
        
        while(next) {          
            a = prev->val;
            b = curr->val;
            c = next->val;                        
            if(b < a && b < c) critical.push_back(i);
            else if(b > a && b > c) critical.push_back(i);
            prev = curr;
            curr = prev->next;
            next = curr->next;
            i++;
        }

        int n = critical.size();
        if(n <= 1) return ans;

        int mini = INT_MAX;        
        ans[1] = critical[n-1] - critical[0];

        for(int i = 0; i < n- 1; i++) {
            mini = min(mini, critical[i+ 1] - critical[i]);
        }

        ans[0] = mini;

        return ans;
        
    }
};