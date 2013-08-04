class Solution {
public:
    int *last,*sub;

    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        
  
        int n = matrix[0].size();
        int * A = new int [n];
        
        int area = 0;
        
        last = new int[n];
        sub = new int[n];
        
        for(int k = 0; k < matrix.size(); k ++){
            for(int t = k; t < matrix.size(); t++){
                
                for(int i = 0; i < matrix[0].size(); i ++){

                    int flag = 0;
                    for(int j = k; j <= t; j ++){
                        if(matrix[j][i] != '1'){
                            flag = 1;
                            break;
                        }
                    }
                    
                    if(flag == 0)
                        A[i] = 1;
                    else 
                        A[i] = 0;

                }
                
                last[0] = A[0];
                sub[0] = A[0];
                
                for(int i = 1; i < n; i ++){
                    if(A[i] == 0){
                        last[i] = 0;
                    }
                    else{
                        last[i] = A[i] + last[i-1];
                    }
                    //last[i] = max(A[i] ,A[i] + last[i-1]);
                    sub[i] = max(sub[i-1],last[i]);
                    
                }
        
                int len = sub[n-1];
                if(len * (t-k+1) >= area)
                    area = len*(t-k+1);
            }
        }
        
        delete A;
        delete last;
        delete sub;
        return area;
        
        
    }
};
