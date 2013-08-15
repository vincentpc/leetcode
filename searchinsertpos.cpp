class Solution {
public:
    int tar;
    
    int bsearch(int A[] ,int begin, int end){
        if(begin > end){
            return begin;
        }
        
        if(begin == end){
            if(tar == A[begin])
                return begin;
            if(tar < A[begin])
                return begin;
            else
                return begin+1;
                
        }
        
        int mid = (begin+end)/2;
        
        if(tar < A[mid]){
            return bsearch(A,begin,mid-1);
        }
        else if(tar > A[mid]){
            return bsearch(A,mid+1,end);
        }
        else
            return mid;
        
    }
    
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0;
        
        if(n == 0)
            return result;
        
        tar = target;
        result = bsearch(A,0,n-1);
        return result;
        
    }
};
