#pragma GCC optimize("OFast")
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        ios::sync_with_stdio(0);
              
        if(edges[0][0] == edges[1][0]) return edges[0][0];
        else if(edges[0][0] == edges[1][1]) return edges[0][0];
        else return edges[0][1];  

        return -1;
    }
};