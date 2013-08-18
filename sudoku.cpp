class Solution {
public:
    
    vector<vector<char> > saveboard;
    int mark[10][11];
    int row[10][11];
    int col[10][11];
    
    bool test(int r,int c){
        
        int nextr = -1,nextc = -1;
        int i,j;

        for(i = r; i < saveboard.size(); i ++){
            if(i == r)
                j = c;
            else
                j = 0;
                
            for(; j < saveboard[0].size(); j ++){
                if(saveboard[i][j] == '.'){
                    nextr = i;
                    nextc = j;
                    break;
                }
            }
            
            if(j != saveboard[0].size())
                break;
        }
        
        if(nextr == -1){
            return true;
        }
        
        r = nextr;
        c = nextc;
        
        for(i = 1; i <= 9; i ++){
            if(mark[(r/3)*3+c/3][i] ==0 && row[r][i] == 0 && col[c][i] ==0){
                mark[(r/3)*3+c/3][i] = 1;
                row[r][i] = 1;
                col[c][i] = 1;    
                saveboard[r][c] = i+'0';
                
                if(test(r,c) == true)
                    return true;
                    
                saveboard[r][c] = '.';
                mark[(r/3)*3+c/3][i] = 0;
                row[r][i] = 0;
                col[c][i] = 0;                    
                
            }
                    
        }
        return false;
        
        
    }
    
    
    
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        saveboard = board;
        
        memset(mark,0,sizeof(mark));
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        
        for(int i = 0; i < board.size(); i ++){
            for(int j = 0; j < board[0].size(); j ++){
                if(board[i][j] != '.'){
                    mark[(i/3)*3+j/3][board[i][j]-'0'] = 1;
                    row[i][board[i][j]-'0'] = 1;
                    col[j][board[i][j]-'0'] = 1;
                }
            }
        }
        
        test(0,0);
        

        board = saveboard;
        return;
        
    }
};
