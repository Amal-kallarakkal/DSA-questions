class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int ans = 0;
        

        while(stones.size() >1) {
            sort(stones.begin(), stones.end());
            int n = stones.size();
            if(stones[n-1] == stones[n-2]) {
                stones.pop_back();
                stones.pop_back();
            } else {
                int diff = (stones[n-1] - stones[n-2]);
                stones.pop_back();
                stones.pop_back();
                stones.push_back(diff);
            }
        }

        if(stones.size()) ans = stones[0];

        return ans;
    }
};