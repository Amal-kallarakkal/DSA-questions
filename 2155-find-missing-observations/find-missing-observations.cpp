class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int m = rolls.size();
        int x = 0;
        int sum = accumulate(rolls.begin(), rolls.end(), 0);

        x = mean*(m + n) - sum;
        // cout<<x<<endl;
        // if() 
        if(6*n < x || x < n) return ans;

        while(n) {
            ans.push_back(x/n);
            x = x -  x/n;
            n--;
            // cout<<x<<" ";
        }

        return ans;
    }
};