class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> arr(n);

        for(int i = 0; i < n; i++) {
            int big = max(s[i] - 96,t[i] - 96);
            int small = min(s[i] - 96, t[i] - 96);
            arr[i] = big - small;            
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