class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = 0, n = nums.size();
        vector<int> circular = nums;

        circular.insert(circular.end(), nums.begin(), nums.end());

        for(int i = 0 ; i <= n; i++ ) {
            maxi = max(maxi, abs(circular[i] - circular[i+1]));
        }
 
        return maxi;
    }
};