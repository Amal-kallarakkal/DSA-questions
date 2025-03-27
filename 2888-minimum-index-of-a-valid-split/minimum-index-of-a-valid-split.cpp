class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = 0, n = nums.size(), dom, cnt = 0;

        for(int i = 0 ; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(auto x: mp) {
            if(maxi < x.second) {
                maxi = x.second;    //freq of dominant element
                dom = x.first;      //dominant element
            }
        }
        
        if(maxi*2 < n) return -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] == dom) cnt++;         //count the freq of dom before partition

            if(cnt*2 > i + 1) {             //check if first half condition is satisfied

                if((maxi - cnt)*2 > n - i - 1)  //check if second half condition is satisfied
                    return i;
            }
        }

            
        return -1;
    }
};