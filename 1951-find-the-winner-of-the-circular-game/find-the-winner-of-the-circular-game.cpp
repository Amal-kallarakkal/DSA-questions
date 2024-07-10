class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circle(n);
        for(int i = 0 ; i < n ; i++) circle[i] = i + 1;
        int i = 0;
        while(circle.size() > 1) {
            i = (i + k -1)%circle.size();
            circle.erase(circle.begin() + i);            
        }

        return circle[0];
    }
};