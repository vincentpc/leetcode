class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
            return 1;
        
        int *p = new int[n+2];
        
        memset(p,0,sizeof(int)*(n+2));
        
        for(int i = 0; i < n; i ++){
            if(A[i] >= 0 && A[i] <= n)
                p[A[i]] = 1;
                
        }
        
        int mark;
        
        for(int i = 1; i <= n+1; i ++)
            if(p[i] != 1){
                mark = i;
                break;
            }
                
        delete p;
        return mark;
    }
};
