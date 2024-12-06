class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0, sum = 0;
        unordered_set<int> set;
        for(int i = 0 ; i < banned.size(); i++) set.insert(banned[i]);
        int i = 1;
        while(i <= n) {
            if(!set.count(i) && sum <= maxSum) {
                sum += i;
                if(sum <= maxSum)ans++;
                // cout<<i<<endl;
            }
            i++;
        }

        return ans;
    }
};