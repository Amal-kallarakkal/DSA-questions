class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int prev_max = 0;
        int P_ind = 0;
        for(int i = 0 ; i < n; i++) {
            if(height[i] >= prev_max) {
                int j = P_ind + 1;
                while(j<i) {
                    ans += prev_max - height[j];
                    j++;
                }
                prev_max = height[i];
                P_ind = i;
            }
        }

        cout<<ans<<endl;
        int Next_max = 0;
        int N_ind = n-1;
        for(int i = n - 1; i >= P_ind; i--) {
            if(height[i] >= Next_max) {
                int j = N_ind - 1;
                while(j>i) {
                    ans += Next_max - height[j];
                    j--;
                }
                Next_max = height[i];
                N_ind = i;
            }    
        }

         cout<<ans<<endl;
        return ans;
    }
};