class Solution {
public:
    // void solve(int l, int r, vector<int>& nums, int &ans) {
    //     if(l >= r) return;
    //     int mid = (l + r)/2, sum = 0;
    //     for(int i = 0 ; i < nums.size(); i++) sum += abs(mid - nums[i]);
    //     cout<<ans<<" > "<<sum<<endl;        
    //     if(sum <= ans) {
    //         ans = sum;    
    //         solve(mid + 1, r, nums, ans);
    //         solve(l, mid - 1 , nums, ans);
    //     } 
    // }
    int minMoves2(vector<int>& nums) {
        int ans = 0;
        int n = nums.size(), mid = n/2, x;
        sort(nums.begin(), nums.end());
        if(n%2 == 0) {
           x = (nums[mid - 1] + nums[mid])/2;
        } else x = nums[mid];
        // for(int x: nums) cout<<x<<" ";
        // cout<<endl;
        // cout<<x<<endl;
        for(int i = 0; i < nums.size(); i++) {
            ans += abs(x - nums[i]);
        }
        return ans;
    }
};