class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int tag,left,count;
        if(n == 0)
            return n;
        
        tag = A[0];
        left = 0;
        count = 2;
        for(int i = 1; i < n; i ++){
            if(A[i] == tag){
                count --;
                continue;
            }
            else{
                A[left++] = tag;
                if(count != 2)
                    A[left++] = tag;
                tag = A[i];
                count = 2;
            }
        }
        
        A[left++] = tag;
        if(count != 2)
            A[left++] = tag;
        return left;
        
    }
};
