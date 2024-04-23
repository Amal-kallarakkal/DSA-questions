class Solution {
public:
    bool neighbour(int i,int j,string &word, vector<vector<char>>& board, vector<vector<int>> &visited) {
        if(word.size() == 0) return true;
        // cout<<"word after each call: "<<word<<endl;
        int row = board.size();
        int col = board[0].size();
        visited[i][j] = 1;

        // up
        if(i > 0) {
            if(word[0] == board[i - 1][j] && (visited[i - 1][j] != 1)) {
                    char a = word[0];
                    word.erase(word.begin() + 0);
                    if(neighbour(i - 1, j, word, board, visited)) return true;
                    
                    word = a + word;
                    
            }
        }

        // down
        if(i < row - 1 ) {
            if(word[0] == board[i + 1][j] && (visited[i + 1][j] != 1)) {
                    char a = word[0];
                    word.erase(word.begin() + 0);
                    if(neighbour(i + 1, j, word, board, visited)) return true;
                    
                    word = a + word;
            }
        }

        // left
        if(j > 0 ) {
            if(word[0] == board[i][j - 1] && (visited[i][j - 1] != 1)) {
                    char a = word[0];
                    word.erase(word.begin() + 0);
                    if(neighbour(i, j - 1, word, board, visited)) return true;
                    word = a + word;
            }
        }

        // right
        if(j < col - 1 ) {
            if(word[0] == board[i][j + 1] && (visited[i][j + 1] != 1)) {
                    char a = word[0];
                    word.erase(word.begin() + 0);
                    if(neighbour(i, j + 1, word, board, visited)) return true;
                    
                    word = a + word;
            }
        }

        // cout<<"after back tracking: "<<word<<endl;
        visited[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        char a = word[0];
        
        if(row * col < word.size()) return false;

        vector<vector<int>> visited( row , vector<int> (col));  
        for(int i=0;i<row;i++) for(int j =0;j<col; j++) visited[i][j] = 0;

        word.erase(word.begin() + 0);
        for(int i = 0 ; i < row ; i++) {
            int ind = 0;
            for(int j = 0; j < col ; j++) {
                
                if(a == board[i][j]) {     
                                    
                   if(neighbour(i, j, word, board, visited)) return true;   
                                    
                }
            }
        }


        return false;


    }
};