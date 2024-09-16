class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> ans;
        int hrs = 0, mins = 0, diff = 0, mini = INT_MAX;
        for(string s: timePoints) {
            hrs = 0, mins = 0;
            for(int i = 0 ; i < s.size(); i++) {
                while(i < 2) {
                    hrs += (s[i] - '0')*pow(10, 1 - i );
                    i++;
                }
                i++;
                while(i < 5) {
                    mins += (s[i] - '0')*pow(10, 4 - i);
                    i++;
                }
                ans.push_back(hrs*60 + mins);
            }
        }

        for(int i = 0 ; i < n - 1 ; i++) {
            for(int j = i + 1; j < n ; j++) {
                diff = abs(ans[i] - ans[j]);
                diff = min(diff, 1440 - diff);            
                mini = min(mini, diff);    
                if(!mini) return mini;
            }
        }
        return mini;
    }
};