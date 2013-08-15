class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int firstrow = 1;
        int firstcol = 1;
        
        
        if(matrix.size() == 0)
            return;
            
        for(int i = 0; i < matrix.size(); i ++){
            if(matrix[i][0] == 0){
                firstcol = 0;
                break;
            }    
        }
        
        for(int i = 0; i < matrix[0].size(); i ++){
            if(matrix[0][i] == 0){
                firstrow = 0;
                break;
            }
        }
        
        for(int i = 0; i < matrix.size(); i ++){
            for(int j = 0; j < matrix[0].size(); j ++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < matrix.size(); i ++){
            if(matrix[i][0] == 0){
                for(int j = 0; j < matrix[0].size(); j ++){
                    matrix[i][j] = 0;
  
                }            
            }
        }
        
        for(int i = 1; i < matrix[0].size(); i ++){
            if(matrix[0][i] == 0){
                for(int j = 0; j < matrix.size(); j ++){
                    matrix[j][i] = 0;
  
                }            
            }
        }
        
        
        if(firstrow == 0){
                for(int j = 0; j < matrix[0].size(); j ++){
                    matrix[0][j] = 0;
  
                }             
        }

        if(firstcol == 0){
                for(int j = 0; j < matrix.size(); j ++){
                    matrix[j][0] = 0;
  
                }             
        }
        return;
        
        
    }
};
