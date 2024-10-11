class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
        unordered_map<int,int> linein;
        unordered_map<int, vector<int>> lineout;

        int ans = -1, n = times.size(), maxi = 0, leave;
        vector<int> chair(n, -1);

        for(int i = 0 ; i < n; i++) {
            linein[times[i][0]] = i + 1;
            lineout[times[i][1]].push_back(i + 1);
            maxi = max(maxi, times[i][1]);
        }
        for(int i = 1 ; i < maxi; i++) {
            while(lineout[i].size() > 0) {
                    // cout<<lineout[i][lineout[i].size() - 1] - 1<<" leaves at time "<<i<<" ";
                    for(int j = 0; j < n; j++) {
                        if(chair[j] == lineout[i][lineout[i].size() - 1] - 1) {
                            chair[j] = -1;
                            lineout[i].pop_back();
                            // cout<<"from chair "<<j<<endl;
                            break;
                        }
                    }
            }
            if(linein[i] > 0) {
                // cout<<linein[i] - 1<<" arrives at time "<<i<<" ";
                for(int j = 0; j < n; j++) {
                        if(chair[j] == -1) {
                            chair[j] = linein[i] - 1;
                            // cout<<" ans sits at chair "<<j<<endl;
                            if(linein[i] - 1 == t) {
                                ans = j;
                                return ans;
                            } 
                            break;
                        }
                }
            } 
        }

        return ans;
    }
};