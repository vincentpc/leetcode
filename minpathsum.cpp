class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int minpath = 100000;
        if(grid.size() == 0)
            return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int a[1000][1000];
        memset(a,0,sizeof(a));
                
        a[0][0] = grid[0][0];
        
        for(int i = 1; i < m; i ++){
            a[i][0] = a[i-1][0] + grid[i][0];
        }
        
        for(int i = 1; i < n; i ++){
            a[0][i] = a[0][i-1] + grid[0][i];
            
        }
        
        for(int i = 1; i < m ; i ++){
            for(int j = 1; j < n; j ++){
                if(a[i-1][j] > a[i][j-1])
                    a[i][j] = a[i][j-1]+grid[i][j];
                else
                    a[i][j] = a[i-1][j]+grid[i][j];
            }
        }
        
        return a[m-1][n-1];
    
    }
};
