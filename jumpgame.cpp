class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int longest= 0;
        
        for(int i = 0; i < n-1; i ++){
            if(longest < i){
                break;
            }
            if(longest >= n-1)
                return true;
            int newstep = i + A[i];
            if(newstep > longest)
                longest = newstep;
        }
        
        if(longest >= n-1)
            return true;
        
        return false;
    }
};
