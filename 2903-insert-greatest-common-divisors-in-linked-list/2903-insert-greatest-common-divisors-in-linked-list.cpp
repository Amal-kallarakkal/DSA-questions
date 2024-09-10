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
    
    private:
    
    void insertAnywhere(ListNode* &head, int value, int gcd) {
        
        ListNode* temp = head;
        ListNode* newNode = new ListNode(gcd);
        
        while(temp->val != value) {
            temp = temp->next;
        }
        
        ListNode* next = temp->next;
        temp->next =  newNode;
        newNode->next = next;
        return;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* curr = head;
        ListNode* next = curr->next;
        
        if(next == NULL) {
            return head;
        }
        
        while(next != NULL) {
            int val1 = curr->val;
            
            int val2 = next->val;
            
            int gcd = __gcd(val1,val2);
            
            ListNode* newNode = new ListNode(gcd);
            
            curr->next = newNode;
            newNode->next = next;
            curr = next;
            next = curr->next;
        }
        
        return head;
    }
};