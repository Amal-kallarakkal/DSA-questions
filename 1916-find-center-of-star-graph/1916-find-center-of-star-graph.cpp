class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int centre = 0;
        
        if(edges[0][0] == edges[1][0]) centre = edges[0][0];
        else if(edges[0][0] == edges[1][1]) centre = edges[0][0];
        else centre = edges[0][1];  
   

        return centre;
    }
};