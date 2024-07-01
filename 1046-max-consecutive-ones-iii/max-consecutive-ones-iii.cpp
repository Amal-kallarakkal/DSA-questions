class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt = 0;
        int ans = 0;
        int maxi = 0;
        int j;
        for(int i = 0 ; i < nums.size()  - maxi; i++) {
            j = i;
            while(j < nums.size() && cnt <= k) {
                if(!nums[j])cnt++;
                if(cnt <= k) j++;
            }
            // cout<<"i: "<<i<<" , j: "<<j<<endl; 
            
            ans = j - i;
            maxi = max(maxi, ans);
            cnt = 0;
            // i = j + maxi - 1;
        }
        return maxi;
    }
};