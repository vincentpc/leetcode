class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int *last,*sub;
        last = new int[n];
        sub = new int[n];
        
        if(n == 0)
            return 0;
        
        last[0] = A[0];
        sub[0] = A[0];
        
        for(int i = 1; i < n; i ++){
            last[i] = max(A[i] ,A[i] + last[i-1]);
            sub[i] = max(sub[i-1],last[i]);
            
        }
        
        int largest = sub[n-1];
        delete last;
        delete sub;
        return largest;
    }
};
