class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = 0, low = INT_MAX;
        for(auto i : logs){
            n = max(n, i[1]);
            low = min(low, i[0]);
        }
        // sort(logs.begin(), logs.end());
        
        // cout<<low<<", "<<n<<endl;
        vector<int> line(n + 1);
        for(auto i : logs){
            line[i[0]]++;
            line[i[1]]--;
        }
        int ans = 0;
        int maxCnt = 0, cnt = 0;
        for(int i = low ; i < n ; i++) {
            cnt += line[i];
            if(cnt > maxCnt) {
                maxCnt = cnt;
                ans = i;
                // c'out<<ans<<", cnt:  "<<cnt<<endl;
            }
        }
        return ans;
    }
};