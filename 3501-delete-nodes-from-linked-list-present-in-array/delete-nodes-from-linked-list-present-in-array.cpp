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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        unordered_set<int> set;
        for(int i = 0 ; i < nums.size(); i++) set.insert(nums[i]);
        while(temp) {
            if(set.count(temp->val)) {
                
                if(temp == head) {
                    head = temp->next;                    
                    prev = NULL;
                } else {
                    prev->next = temp->next;
                    temp = temp->next;
                    continue;
                }                
            }
            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};


static const int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();