class Solution {
public:
    int mark[1000][1000];
    string target;
    vector<vector<char> > b;
    
    bool test(int begin,int row,int col){

            
        if(b[row][col] != target[begin])
            return false;
            
        if(begin+1 == target.size())
            return true;      
            
        if(row-1>= 0 && mark[row-1][col] == 0){
            mark[row-1][col] = 1;
            if(test(begin+1,row-1,col) == true)
                return true;
            mark[row-1][col] = 0;
        }
            
        if(row+1 <= b.size()-1  && mark[row+1][col] == 0){
            mark[row+1][col] = 1;
            if(test(begin+1,row+1,col) == true)
                return true;
            mark[row+1][col] = 0;
        }
        
        if(col-1>= 0 && mark[row][col-1] == 0){
            mark[row][col-1]  = 1;
            if(test(begin+1,row,col-1) == true)
                return true;
            mark[row][col-1]  = 0;
        }
        
        if(col+1 <= b[0].size()-1  && mark[row][col+1] == 0){
            mark[row][col+1]  = 1;
            if(test(begin+1,row,col+1) == true)
                return true;
            mark[row][col+1]  = 0;
        }
        

            
        return false;
        
        
    }
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        memset(mark,0,sizeof(mark));
        b = board;
        target = word;
        if(target.size() == 0)
            return true;
        
        if(board.size() == 0)
            return false;
            
        for(int i = 0; i < board.size(); i ++){
            for(int j = 0; j < board[0].size(); j ++){
                if(board[i][j] == target[0]){
                     mark[i][j] = 1;
                     if(test(0,i,j) == true)
                        return true;
                     mark[i][j] = 0;
                     
                }
                   
            }
        }
        return false;
  
    }
};
