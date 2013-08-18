class Solution {
public:
    vector<vector<char>> thisboard;

    bool test(int row,int col){

        thisboard[row][col] = '+';
        
        
        if(row-1 >= 0 && thisboard[row-1][col] == 'O'){
            test(row-1,col);
        }
        if(row+1 <= thisboard.size() -1 && thisboard[row+1][col] == 'O'){

            test(row+1,col);

        }
        if(col-1 >= 0 && thisboard[row][col-1] == 'O'){

            test(row,col-1);

        }
        
        if(col+1 <= thisboard[0].size()-1 && thisboard[row][col+1] == 'O'){
            test(row,col+1);

        }
        

        return true;
    }
    
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(board.size() == 0)
            return;
        thisboard.clear();
        thisboard = board;
        
        for(int i =0; i < thisboard.size(); i ++){

                if(thisboard[i][0] == 'O'){                    
                    test(i,0);
 
                }

                if(thisboard[i][thisboard[0].size()-1] == 'O'){                    
                    test(i,thisboard[0].size()-1);
 
                }            
        }

        for(int i = 0; i < thisboard[0].size(); i ++){

                if(thisboard[0][i] == 'O'){                    
                    test(0,i);
                }

                if(thisboard[thisboard.size()-1][i] == 'O'){                    
                    test(thisboard.size()-1,i);
                    
                }            
        }

        for(int i = 0; i < thisboard.size(); i ++){
            for(int j = 0; j < thisboard[0].size(); j ++){
                if(thisboard[i][j] == 'O')
                    thisboard[i][j] = 'X';
                else if(thisboard[i][j] == '+')
                    thisboard[i][j] = 'O';
                    
            }
        }
        board = thisboard;
        
        return;
        
    }
};
