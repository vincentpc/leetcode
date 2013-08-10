class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> results;
        
        if(numRows == 0)
            return results;
        
        int a[100],b[100];
        a[0] = 1;
        for(int i = 0; i < numRows; i ++){
            vector<int> res;
            
            for(int j = 0; j <= i; j ++){
                if(j == 0){
                    b[j] = 1;
                }
                else if(j == i){
                    b[j] = 1;
                }
                else{
                    b[j] =  a[j-1]+a[j];
                    
                }
                
                res.push_back(b[j]);
            }
            memcpy(a,b,sizeof(a));
            
            results.push_back(res);
        }
        
        return results;
    }
};
