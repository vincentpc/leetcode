class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int i,j,sum = 0;
        int a[110][110];
        
        int m = obstacleGrid.size();
        if(m == 0)
            return 0;
            
        int n = obstacleGrid[0].size();
        
        memset(a,0,sizeof(a));
        
        for(i = 0; i < m; i ++){
            if(obstacleGrid[i][0] == 1)
                break;
            a[i][0] = 1;
        }
        
        for(i = 0; i < n; i ++){
            if(obstacleGrid[0][i] == 1)
                break;
            a[0][i] = 1;
        }
        
        for(i = 1; i < m; i ++){
            for(j = 1; j < n; j ++){
                if(obstacleGrid[i][j] == 1)
                    a[i][j] = 0;
                else
                    a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        
        return a[m-1][n-1];
        
    }
};
