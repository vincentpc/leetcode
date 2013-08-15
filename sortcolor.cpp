class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int r= 0,w= 0, b= 0;
        
        for(int i = 0; i < n; i ++){
            if(A[i] == 0)
                r++;
            if(A[i] == 1)
                w++;
            if(A[i] == 2)
                b++;
                
        }
        
        int i = 0;
        for(i = 0; i < r; i ++)
            A[i] = 0;
        for(; i < r+w; i ++)
            A[i] = 1;
        for(; i < r+w+b; i ++)
            A[i] = 2;
        return;
    }
};
