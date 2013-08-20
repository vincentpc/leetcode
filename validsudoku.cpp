class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row[10][10];
        int col[10][10];
        int mark[10][10];
        
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(mark,0,sizeof(mark));
        
        for(int i = 0; i < board.size(); i ++){
            for(int j = 0; j < board[0].size(); j ++){
                if(board[i][j] != '.'){
                    int now = board[i][j] - '0';
                    if(row[i][now] != 0)
                        return false;
                    if(col[j][now] != 0)
                        return false;
                    if(mark[i/3*3+j/3][now] != 0)
                        return false;
                        
                    row[i][now] = 1;
                    col[j][now] = 1;
                    mark[i/3*3+j/3][now] = 1;
                }
            }
        }
        return true;
        
    }
};
