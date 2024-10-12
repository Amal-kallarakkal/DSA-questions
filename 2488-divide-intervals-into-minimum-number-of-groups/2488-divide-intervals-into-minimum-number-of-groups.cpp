class Solution {
public:
    int minGroups(vector<vector<int>>& nums) {
        int maxi = 0, cnt = 0;
        vector<pair<int, int>> line;

        for(int i = 0 ; i < nums.size(); i++) {            
            line.push_back({nums[i][0], 1});
            line.push_back({nums[i][1] + 1, -1});
        }

        sort(line.begin(), line.end());
        
        for(auto x: line) {
            if(x.second == 1)  {
                cnt++;
                maxi = max(cnt, maxi);
            } else if(cnt)cnt--;
        }    

        return maxi;
    }
};