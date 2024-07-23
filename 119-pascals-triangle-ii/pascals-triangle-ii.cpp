class Solution {
public:

    long long int fact(long long int x){
        //base case
        if(x == 1 || x == 0){
            return 1;
        }

        return x*fact(x-1);
    }

    long long int comb(int n, int i) {

        long long int ans = fact(n)/fact(i);
        long long int ans2 = ans / fact(n-i);
        return ans2;
    }
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> nums(rowIndex + 1);
        // nums[0][0] = 1;
        // nums[1].push_back(1);
        // nums[1].push_back(1);

        int n = rowIndex;
        for(int i = 0 ; i <= n ; i++) {
            for(int j = 0 ; j < i+1 ; j++ ) {
                if(j == 0 || j == i ){
                    nums[i].push_back(1);
                } else {
                    int sum = nums[i-1][j-1] + nums[i-1][j];
                    nums[i].push_back(sum);
                }               
            }            
        }
        int k = 0;
        vector<int> ans;
        for(auto x: nums) {
            k++;
            if(k == n+1)for(auto y : x) ans.push_back(y);
            
        }
        
        return ans;
        // return nums[n - 1];
    }
    
};