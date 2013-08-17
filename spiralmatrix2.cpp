class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        
        result.clear();
        
        
 
        if(n == 0)
            return result;
        
    
        
        
        int m = n;
        
        int left = 0,right = m-1;
        int up = 0, down = n-1;
        int count = 1;
        int i,j;
        
        for(i = 0; i < n; i ++){
            vector<int> res;
            for(j = 0; j < n; j ++){
                res.push_back(0);
            }
            result.push_back(res);
            
        }
        while(left <= right && up <= down){
            
            for(i = left; i <= right; i ++){
                result[up][i] = count++;
                
            }
            
            for(i = up+1; i < down; i ++){
                result[i][right] = count++;
            }
            

            if(up != down){
                for(i = right; i >= left; i --){
                    result[down][i] = count++;
                }
            }
            
            if(left != right){
                for(i = down-1; i > up; i --){
                    result[i][left] = count++;
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
