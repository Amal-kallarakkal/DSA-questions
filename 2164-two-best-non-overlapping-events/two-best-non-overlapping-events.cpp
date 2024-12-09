class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size(), maxi = 0, ans = 0, sum, target, l, h, mid, curr;
        // vector<int> mp(1e6);
        unordered_map<int, int> mp;
        sort(events.begin(), events.end());

        for(int i = n - 1 ; i >= 0; i--) {
            maxi = max(maxi, events[i][2]);
            mp[events[i][0]] = maxi;
        }

        for(int i = 0 ; i < n ; i++) {
            sum = events[i][2];
            target = events[i][1];
            l = i + 1;
            h = n - 1;
            curr = -1;
            while(l <= h) {
                mid = (l + h)/2;
                if(target < events[mid][0]) {
                    curr = events[mid][0];
                    h = mid - 1;
                } else l = mid + 1;
            }
            if(curr != -1) {
                sum += mp[curr];
            }
            ans = max(sum , ans);
        }
        return ans;
    }
};