class Solution {
public:
    int a[15000][50];
    
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        a[0][0] = 1;
        
        for(int i = 1; i <= S.length(); i ++)
            a[i][0] = 1;
        
        for(int i = 1; i <= T.length(); i ++)
            a[0][i] = 0;
            
        for(int i = 1; i <= S.length(); i ++){
            for(int j = 1; j <= T.length(); j ++){
                a[i][j] = 0;
                if(S[i-1] == T[j-1])
                    a[i][j] += a[i-1][j-1];
                a[i][j] +=a[i-1][j];
            }
        }
        
        return a[S.length()][T.length()];
        
        
    }
};
