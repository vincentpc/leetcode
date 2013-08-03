class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int longest= 0;
        int step[100000];
        memset(step,0,sizeof(step));
        
        if(n == 1)
            return 0;
        
        for(int i = 0; i < n-1; i ++){

            if(longest >= n-1)
                break;
            int newstep = i + A[i];
            if(newstep > longest){
            
                for(int j = longest+1; j <= newstep; j ++)
                    step[j] = step[i]+1;
                
                longest = newstep;
                
            
            }
        }
        
        return step[n-1];
        
    }
};
