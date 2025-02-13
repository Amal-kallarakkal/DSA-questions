using ll = long long;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // vector<ll> nums = nums1;
        ll cnt = 0, temp, a, b;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int &i: nums ) pq.push(i);
        while(k > pq.top() && pq.size() > 1) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            pq.push(2*a + b);
            cnt++;
        }
        return cnt;
    }
};