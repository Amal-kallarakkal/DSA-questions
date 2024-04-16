class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int prev_max = 0;
        int res = 0;
        int P_ind = 0;
        for(int i = 0 ; i < n; i++) {
            if(height[i] >= prev_max) {                
                prev_max = height[i];
                P_ind = i;
                res += ans;
                ans = 0;
            }
            else ans += prev_max - height[i];
        }

        
        cout<<res<<endl;
        int Next_max = 0;
        ans = 0;
        int N_ind = n-1;
        for(int i = n - 1; i >= P_ind; i--) {
            if(height[i] >= Next_max) {
                Next_max = height[i];
                N_ind = i;
                res += ans;
                ans = 0;
            } 
            else ans += Next_max - height[i];   
        }

        //  cout<<ans<<endl;
        return res;
    }
};