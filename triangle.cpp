class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a[1000],b[1000];
        int n = triangle.size();
        int sum = 0;
        memset(a,0,sizeof(a));
        
        if(n == 0){
            return sum;
        }
        
        int i,j;
        
        for(i = 0; i < n; i ++){
            a[i] = triangle[n-1][i];
        }
        
        for(i = n -2; i >= 0; i --){
            for(j = i; j >= 0; j --){
                b[j] = min(a[j],a[j+1]) + triangle[i][j];
            }
            memcpy(a,b,sizeof(a));
        }
            
        return a[0];
    }
};
