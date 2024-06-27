class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int centre = 0;
        unordered_map<int,int> mp;
        int maxi = 0;
        for(int i =0 ; i < edges.size(); i++) {
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }

        for(auto x: mp) {
            if(maxi < x.second) {
                centre = x.first;
                maxi = x.second;
            }
        }

        return centre;
    }
};