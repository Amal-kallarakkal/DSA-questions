using ll = long long;
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        ll sum = 0, n = gifts.size(), top;
        priority_queue<int> pq;
        for(int i = 0 ; i < n; i++) {
            pq.push(gifts[i]);
        }
        while(k--) {
            top = pq.top();
            pq.pop();
            pq.push(floor(sqrt(top)));
        }
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};