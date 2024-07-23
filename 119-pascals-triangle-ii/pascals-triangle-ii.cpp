class Solution {
public:

    vector<int> getRow(int rowIndex) {
        vector<vector<int>> nums(rowIndex + 1);
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
    
        return nums[n];
       
    }
    
};