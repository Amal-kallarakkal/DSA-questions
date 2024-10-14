using ll = long long;
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ll ans = 0;
        priority_queue<int> pq;
        for(int i = 0 ; i < nums.size(); i++) pq.push(nums[i]);
        int i = 0, top;
        while(i < k && !pq.empty()) {
            top = pq.top();
            pq.pop();
            ans += top;
            top = ceil(top/3.0);
            // cout<<top<<endl;
            pq.push(top);
            i++;
        }
        return ans;
    }
};