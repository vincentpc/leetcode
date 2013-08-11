class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int tag,left;
        if(n == 0)
            return n;
        
        tag = A[0];
        left = 0;
        for(int i = 1; i < n; i ++){
            if(A[i] == tag){
                continue;
            }
            else{
                A[left++] = tag;
                tag = A[i];
            }
        }
        
        A[left++] = tag;
        return left;
        
    }
};
