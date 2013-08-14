class Solution {
public:
    vector<int> result;
    int size;
    int tar;
    void bsearch(int A[],int begin,int end){
        if(begin > end){
            return;
        }
        
        int mid = (begin+end)/2;
        
        if(A[mid] < tar){
            bsearch(A,mid+1,end);
        }
        else if(A[mid] > tar){
            bsearch(A,begin,mid-1);
        }
        else{
            int left = mid,right = mid;
            while(A[left] == tar && left >= 0)
                left --;
            while(A[right] == tar && right < size)
                right++;
            result.push_back(left+1);
            result.push_back(right-1);
        }
        
    }
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        tar = target;
        size = n;
        result.clear();
        bsearch(A,0,n-1);
        
        if(result.size() == 0){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        return result;
        
    }
};
