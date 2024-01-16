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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* temp = head;
        map<int, int> mp;

        while(temp != NULL) {
            mp[temp->val]++;
            temp = temp->next;
        }
        ListNode* head2 = new ListNode();
        ListNode* temp2 = head2;
        for(auto x: mp) {
            if(x.second == 1){
                ListNode* newNode = new ListNode(x.first);
                temp2->next = newNode;
                temp2 = temp2->next;
            }
        }

        head2 = head2->next;

        return head2;

    }
};