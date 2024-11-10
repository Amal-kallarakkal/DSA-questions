class Solution {
public:
    void add(map<int, int> &mp, int temp ) {
            int i = 0;
            while(temp) {
                if(temp%2) mp[i]++;
                temp = temp>>1;
                i++;
            }
    }
    
    void remove(map<int, int> &mp, int temp) {
         int i = 0;
            while(temp) {
                if(temp%2) mp[i]--;
                temp = temp>>1;
                i++;
            }
    }

    int solve(map<int, int> &mp) {
        int ans  = 0;
        for(auto x : mp) {
            if(x.second > 0) ans += pow(2, x.first);
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX, n = nums.size(), orval = 0, j =0, temp, l;
        map<int, int> mp;
        for(int i = 0 ; i < n ; i++){
            temp = nums[i];
            orval |= nums[i];
            add(mp, nums[i]);
            while(orval >= k && j <= i ) {
                ans = min(ans, i - j + 1);                 
                remove(mp, nums[j++]);
                orval = solve(mp);
            }          
        }
               
        return (ans == INT_MAX)? -1 : ans;
    }
};