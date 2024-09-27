class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> line;        
        for(auto i : logs){
            line[i[0]]++;
            line[i[1]]--;
        }
        int ans = 0;
        int maxCnt = 0, cnt = 0;
        for(auto &i: line) {
            cnt += i.second;
            if(cnt > maxCnt) {
                maxCnt = cnt;
                ans = i.first;
            }
        }
        return ans;
    }
};