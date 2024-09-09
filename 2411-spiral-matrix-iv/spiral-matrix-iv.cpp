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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        ListNode* temp = head;
        int row = 0, col = 0;
        int minrow = 0, mincol = 0, maxrow = m - 1, maxcol = n - 1;
        while(temp) {
            // top-left
            if(row == minrow && col == mincol) {
                minrow++;
                while(col <= maxcol) {
                    if(!temp) break;
                    ans[row][col] = temp->val;
                    col++;
                    temp = temp->next;                    
                }cout<<endl;
                col--;
                row++;
            }
            // top-right
            if(row == minrow && col == maxcol) {
                maxcol--;
                while(row <= maxrow) {
                    if(!temp) break;
                    ans[row][col] = temp->val;
                    row++;
                    temp = temp->next;                    
                }
                row--;
                col--;
            }

            // bot-right
            if(row == maxrow && col == maxcol) {
                maxrow--;
                while(col >= mincol) {
                    if(!temp) break;
                    ans[row][col] = temp->val;                    
                    col--;
                    temp = temp->next;                    
                }
                col++;
                row--;
            }

            // bot-left
            if(row == maxrow && col == mincol) {
                mincol++;
                while(row >= minrow) {
                    if(!temp) break;
                    ans[row][col] = temp->val;                   
                    row--;
                    temp = temp->next;                    
                }
                row++;
                col++;
            }
            if(row < minrow || col < mincol) break;
        }

        return ans;
    }
};