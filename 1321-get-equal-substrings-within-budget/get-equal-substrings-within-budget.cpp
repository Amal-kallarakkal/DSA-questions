class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        ios::sync_with_stdio(0);
        int n = s.size();
        vector<int> arr(n);

        for(int i = 0; i < n; i++) {
            arr[i] = abs(s[i] - t[i]);            
        }
        int st = 0;
        int e = st;
        int maxCnt = 0;
        int sum = 0;
        while (e < n) {
            sum += arr[e];

            while (sum > maxCost) {
                sum -= arr[st];
                st++;
            }

            maxCnt = max(maxCnt, e - st + 1);
            e++;
        }

        return maxCnt;
    }
};