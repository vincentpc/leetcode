class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left,right;
        int n,m;
        if(matrix.size() == 0)
            return;
        
        int save[100];
        n = matrix.size();
        
        left = 0;
        right = n -1;
        int i ,j;
        
        while(left < right){
            
            for(i = left+1; i <= right; i ++){
                save[i] = matrix[left][i];
            }
            
            for(i = left+1, j = right-1; i <= right; i ++, j--){
                matrix[left][i] = matrix[j][left];
            }
            
            for(i = right - 1, j = right - 1; i>= left; i --, j --){
                matrix[i][left] = matrix[right][j];
            }
            
            for(i = right-1, j = left+1; j <= right;i --, j ++){
                matrix[right][i] = matrix[j][right];
                    
            }
            
            for(i = left+1, j = left+1; i <= right; i ++, j ++){
                matrix[i][right] = save[j];
            }
            
            left ++;
            right --;
            
        }
        return;
        
    }
};
