class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int row = grid.size(), k = 0, median, mul, col = grid[0].size(), sum = 0, n = row*col;
        vector<int> nums(n);
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col ; j++) {
                nums[k++] = grid[i][j];
            }
        }
        sort(nums.begin(), nums.end());

        median =  nums[n/2];
        
        for(int i : nums) {
            mul = abs(i - median);
            if(mul%x) return -1;
            sum += abs(i - median)/x;
        }
        return sum;

    }
};