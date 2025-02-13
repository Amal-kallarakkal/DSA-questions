using ll = long long;
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, vector<ll>> sum;
        ll maxsum = -1, digitsum, temp;
        for(int i = 0 ; i < nums.size(); i++) {
            temp = nums[i];
            digitsum = 0;
            while(temp) {
                digitsum += temp%10;
                temp /= 10 ;
            }
            // cout<<digitsum<<endl;
            sum[digitsum].push_back(nums[i]);
        }
        for(auto num : sum) {
            if(num.second.size() > 1) {
                sort(num.second.begin(), num.second.end());
                for(int j = num.second.size()-2 ; j < num.second.size() - 1; j++) {
                    maxsum = max(maxsum, num.second[j] + num.second[j+1]);
                }
            }
        }
        return maxsum;
    }
};