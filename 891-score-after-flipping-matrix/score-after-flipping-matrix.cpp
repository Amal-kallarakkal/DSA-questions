class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        ios::sync_with_stdio(0);
        int row = grid.size();
        int col = grid[0].size();
        // row flip
        for(int i = 0 ; i< row; i++) { 
            if(grid[i][0] == 0 ) {
                for(int j = 0 ; j< col; j++) grid[i][j] = !grid[i][j];
            }
        }

        // col flip
        for(int j = 0 ; j < col; j++){
            int cnt1 = 0;
            for(int i = 0; i < row; i++) {
                if(grid[i][j] == 1) cnt1++;
            }
            if(cnt1 <= row/2) {
                cout<<"cnt1 :"<<cnt1<<endl;
                for(int i = 0; i < row; i++) grid[i][j] = !grid[i][j];
            }
        }

        int sum = 0;
        for(int i = 0 ; i< row; i++)
            for(int j = 0 ; j< col; j++) sum += grid[i][j]*pow(2,col-1 -j);
             
               
               
        return sum;
    }
};