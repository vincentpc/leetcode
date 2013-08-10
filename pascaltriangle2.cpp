class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        
 
        
        int a[100],b[100];
        a[0] = 1;
        for(int i = 0; i <= rowIndex; i ++){
            
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
                
            }
            memcpy(a,b,sizeof(a));
            
        }
        
        for(int i = 0; i <= rowIndex; i ++)
            res.push_back(a[i]);
        return res;
    }
        
    
};
