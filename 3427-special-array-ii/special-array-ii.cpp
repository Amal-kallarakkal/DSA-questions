class Solution {
public:
    int leftbs(int x, vector<int> &nums) {
        int l, h , mid, ans = -1;
        l = 0;
        h = nums.size() - 1;
       
        while(l <= h) {
            mid = (l + h)/2;
            if(x < nums[mid]) {
                ans = nums[mid];
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;

    }

    int rightbs(int x, vector<int> &nums) {
        int l, h , mid, ans = -1;
        l = 0;
        h = nums.size() - 1;
        
        while(l <= h) {
            mid = (l + h)/2;
            if(x >= nums[mid]) {
                ans = nums[mid];
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;

    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size(), sum = 0, left, right;
        vector<bool> ans(n);
        vector<int> flag;
        string temp;
        for(int i = 0 ; i < nums.size() - 1; i++) {
            sum = nums[i] + nums[i+1];
            // cout<<sum<<endl;
            if(sum% 2 == 0) flag.push_back(i+1);
        }
        // for(int i : flag) cout<<i<<" ";
        // cout<<endl;
        for(int i = 0 ; i < n; i++) {
            //
            left = leftbs(queries[i][0], flag);
            right = rightbs(queries[i][1], flag);
            // cout<<queries[i][0]<<", "<<queries[i][1]<<" : "<<left<<" , "<<right<<endl;
            if(left > right || left == -1 || right == -1) ans[i] = true;
        }

        return ans;
    }
};