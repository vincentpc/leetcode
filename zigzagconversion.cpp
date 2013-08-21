class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int n = s.size();
        int m = 2*nRows - 2;
        string result = "";
        
        if(nRows == 1 || nRows > n)
            return s;
            
        for(int i = 1; i <= nRows; i ++){
            int start = i-1;
            if(i == 1 || i == nRows){
                
                while(start < n){
                    result += s[start];
                    start += m;
                }
               
            } 
            else{
                while(start < n){
                    result += s[start];
                    start += (nRows-i)*2;
                    if(start >= n)
                        break;
                    result += s[start];
                    start += (i-1)*2;
                }
            }
        }
        return result;
        
    }
};
