class Solution {
public:
    int solve(vector<vector<int>>& grid,int x,int y){
        int d1=0,d2=0,z=x+y;
        vector<int>rSum(3,0),cSum(3,0);
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                rSum[i-x]+=grid[i][j];
                cSum[j-y]+=grid[i][j];
                if(i+j==z) d1+=grid[i][j];
                if(i+j==x+y+2) d2+=grid[i][j];
            }
            z+=2;
        }
        for(int i=0;i<3;i++){
            if(rSum[i]!=cSum[i]) return 0;
        }
        if(d1==rSum[0] && d1==d2) return 1;
        return 0;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        unordered_set<int>s;
        if(m<3 || n<3) return 0;
        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
                for(int I=i;I<i+3;I++){
                for(int k=j;k<j+3;k++){
                    if(grid[I][k]>=1 && grid[I][k]<=9){
                        s.insert(grid[I][k]);
                    }
                    else{
                        s.clear();
                        break;
                    }
                }
                }
                if(s.size()==9) ans+=solve(grid,i,j);
                else s.clear();
            }
        }
        return ans;
    }
};

/* 
 [9,8,3] 20
 [4,5,6] 15
 [7,2,1] 10

 20 15 10
 
*/