class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

        pair<int, int> mini1 = {-1, INT_MAX};
        pair<int, int> mini2 = {-1, INT_MAX};
        pair<int, int> maxi1 = {-1, -INT_MAX};
        pair<int, int> maxi2 = {-1, -INT_MAX};
        int n;
        for(int i = 0 ; i < arrays.size(); i++){
            n = arrays[i].size() - 1;
            if(arrays[i][0] < mini1.second) {
                mini2 = mini1;
                mini1 = {i,arrays[i][0]};
            } else if(arrays[i][0] < mini2.second) {
                mini2 = {i,arrays[i][0]};
            }

            if(arrays[i][n] > maxi1.second) { 
                maxi2 = maxi1;
                maxi1 = {i, arrays[i][n]};
            } else if(arrays[i][n] > maxi2.second) { 
                maxi2 = {i, arrays[i][n]};
            }
                        
        }
        
        if(maxi1.first != mini1.first) {
            return maxi1.second - mini1.second;
        } else {
            return max(maxi1.second - mini2.second, maxi2.second - mini1.second);
        }
        return 1;
    }
};


/*

[3, 5, 3] = 5
[1, 4, 1] = 1


[[2,3],[1,4,6],[2,3,4]]

[3, 6, 4] = 5
[2, 1, 2] = 1

*/