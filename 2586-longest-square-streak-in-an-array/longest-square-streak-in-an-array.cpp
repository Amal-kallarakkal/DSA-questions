using ll = long long int;
int m = pow(10, 8) + 7;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> set;
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < nums.size(); i++) set.insert(nums[i]);

        int ans = -1, cnt = 0;
        ll temp;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 317) temp = ((nums[i])%m*(nums[i])%m)%m;
            else temp = 0;
            cnt = 0;
            while(set.count(temp) &&temp) {
                temp = temp*temp;
                cnt++;
            }
            if(cnt) ans = max(ans, cnt + 1) ;
        }
        return ans;
    }
};