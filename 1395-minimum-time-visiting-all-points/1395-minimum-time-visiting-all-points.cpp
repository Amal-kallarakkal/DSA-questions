class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if(points.size() == 1) return 0;

        int x1, y1, x2, y2, ans = 0;

        x1 = points[0][0];
        y1 = points[0][1];

        for(int i = 1; i< points.size() ; i++) {
            
            x2 = points[i][0];
            y2 = points[i][1];
           
            ans += max(abs(x2 - x1), abs(y2 - y1));

            x1 = x2;
            y1 = y2;
            
        }

        return ans;
    }
};


/* 

 (1,1) and (3, 4)
 4 - 1 = 2 //ver = 3
 4 - 1 = 2 + 1  //hor = 3
         3
(3,4) and (-1, 0)
3  - - 1 = 4
4 - 0 = 4
    = 4 + 3 = 7
*/