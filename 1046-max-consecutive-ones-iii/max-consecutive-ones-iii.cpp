class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt = 0;
        int ans = 0;
        int maxi = 0;
        int j = 0;
        for(int i = 0 ; i < nums.size()  - maxi; i++) {
            
            while(j < nums.size() && cnt <= k) {
                if(!nums[j])cnt++;
                if(cnt > k) {
                    cnt--;
                    break;
                }
                j++;
                //  if(cnt > k) j--;
            }
            cout<<"i: "<<i<<" , j: "<<j<<endl; 
            // cout<<"cnt : "<<cnt<<endl;
            ans = j - i ;
            maxi = max(maxi, ans);
            if(!nums[i]) cnt--;
            // i = j + maxi - 1;
        }
        return maxi;
    }
};