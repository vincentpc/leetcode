class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a[110][110];
        memset(a,0,sizeof(a));
        int i,j;
        
        for(i = 0; i < m; i ++){
            a[i][0] = 1;
        }
        for(i = 0; i < n; i ++){
            a[0][i] = 1;
        }
        
        for(i = 1; i < m; i ++){
            for(j = 1; j < n; j ++){
                a[i][j] = a[i-1][j]+a[i][j-1];
            }
        }
        
        return a[m-1][n-1];
    }
};
