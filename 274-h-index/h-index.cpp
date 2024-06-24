class Solution {
public:
    void solve(vector<int>& nums, int high, int low, int &maxi, int &ans) {
        if(low > high) {
            return ;
        }
        if(high == 0) return;
        int mid = (low + high)/2;
        if(!mid) mid = 1;
        int n = nums.size();
        int i = n - 1;
        int cnt = 0;
        while(i >= 0 && mid <= nums[i]) {
            cnt++;
            i--;
        }
        if(cnt >= mid) {
            maxi = cnt;
            ans = mid;
            // cout<<ans<<" , maxi: "<<maxi<<endl;
            solve(nums, high, mid + 1, maxi, ans);
        } else  {
            solve(nums, mid-1, low, maxi, ans);
        }

        return;
    }
    int hIndex(vector<int>& citations) {
        int maxi = 0;
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int high = citations[n -1], low = citations[0];
        int ans = low;
        solve(citations, high, low, maxi, ans);

        return min(n, ans);
    }
};