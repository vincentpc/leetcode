class Solution {
public:
    int tar;
    
    int bsearch(int A[],int begin,int end){
        if(begin > end)
            return -1;
        
        int mid = (begin+end)/2;
        if(A[mid] > tar){
            if(A[mid] <  A[begin])
                return bsearch(A,begin,mid-1);
            else if(A[mid] == A[begin]){
                if(A[mid] == A[end])
                    return bsearch(A,begin+1,end-1);
                else if(A[mid] < A[end])
                    return bsearch(A,begin,mid-1);
                else
                    return bsearch(A,mid+1,end);
                    
            }
            else{
                if(tar == A[begin])
                    return begin;
                else if(tar > A[begin]){
                    return bsearch(A,begin,mid-1);
                }
                else{
                    return bsearch(A,mid+1,end);
                }
            }
        }
        else if(A[mid] < tar){
            if(A[mid] > A[end]){
                return bsearch(A,mid+1,end);
            }
            else if(A[mid] == A[end]){
                if(A[begin] == A[mid])
                    return bsearch(A,begin+1,end-1);
                else if(A[begin] < A[mid])
                    return bsearch(A, mid+1,end);
                else
                    return bsearch(A,begin,mid-1);
            }
            else{
                if(tar == A[end])
                    return end;
                else if(tar < A[end]){
                    return bsearch(A,mid+1,end);
                }
                else{
                    return bsearch(A,begin,mid-1);
                }
            }
            
        }
        else
            return mid;
        
        
    }
    
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = -1;
        if(n == 0)
            return false;
        tar = target;
        
        result = bsearch(A,0,n-1);
        if(result == -1)
            return false;
        return true;
    }
};
