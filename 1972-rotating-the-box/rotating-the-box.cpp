class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int row = box.size(), col = box[0].size(), l, r;
        vector<vector<char>> ans(col, vector<char>(row, '.'));

        for(int i = 0; i < row; i++) {            
            for(int j = col - 1; j >= 0; j--) {
                if(box[i][j] == '.') {
                    l = j;
                    while(l >= 0 &&  box[i][l] != '*') l--;
                    r = j;
                    j = l;
                    if(l < 0) l = 0;
                    while(l < r && l >= 0) {
                        while(r >= 0 && box[i][r] != '.') r--;
                        while(l < col && box[i][l] != '#') l++;
                        if(l < r) swap(box[i][l++], box[i][r--]);
                    }                    
                }
            }            
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0 ; j < col; j++) ans[j][i] = box[row - 1 - i][j];
        }


        return ans;
    }
};


