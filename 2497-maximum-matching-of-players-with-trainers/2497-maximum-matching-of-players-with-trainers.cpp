class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int cnt = 0;

        int n = trainers.size(), m = players.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(players[i] <= trainers[j]) {
                cnt++;
                i++;
                j++;
            } else j++;
        }
        return cnt;

    }
};