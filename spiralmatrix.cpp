class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        
        result.clear();
        
        int n = matrix.size();
        if(n == 0)
            return result;
            
        int m = matrix[0].size();
        int left = 0,right = m-1;
        int up = 0, down = n-1;
        
        int i,j;
        
        while(left <= right && up <= down){
            
            for(i = left; i <= right; i ++){
                result.push_back(matrix[up][i]);
                
            }
            
            for(i = up+1; i < down; i ++){
                result.push_back(matrix[i][right]);
            }
            

            if(up != down){
                for(i = right; i >= left; i --){
                    result.push_back(matrix[down][i]);
                }
            }
            
            if(left != right){
                for(i = down-1; i > up; i --){
                    result.push_back(matrix[i][left]);
                }
            }
            left ++;
            right --;
            up ++;
            down --;
        }
        
        
        return result;
        
    }
};
