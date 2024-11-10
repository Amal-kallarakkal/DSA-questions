class Solution {
public:
    void change(unordered_map<int, int> &mp, int temp , string op) {
            int i = 0;
            while(temp) {
                if(temp%2) (op == "+") ?mp[i]++ : mp[i]--;
                temp = temp>>1;
                i++;
            }
    }

    int solve(unordered_map<int, int> &mp) {
        int ans  = 0;
        for(auto x : mp) {
            if(x.second > 0) ans += pow(2, x.first);
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int ans = INT_MAX, n = nums.size(), orval = 0, j =0;
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n ; i++){
            orval |= nums[i];
            change(mp, nums[i], "+");
            while(orval >= k && j <= i ) {
                ans = min(ans, i - j + 1);                 
                change(mp, nums[j++], "-");
                orval = solve(mp);
            }          
        }
               
        return (ans == INT_MAX)? -1 : ans;
    }
};