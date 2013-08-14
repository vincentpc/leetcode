class Solution {
public:

    bool bsearch(vector<int> mat,int begin,int end,int target){
        if(begin > end)
            return false;

        
        int mid = (begin+end)/2;
        
        if(mat[mid] < target){
            return bsearch(mat,mid+1,end,target);
            
        }
        else if(mat[mid] > target){
            return bsearch(mat,begin,mid-1,target);
        }
        else 
            return true;
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size() == 0)
            return false;
        int left = matrix.size() -1 ; 
        
        for(int i = 0; i < matrix.size(); i ++){
            if(matrix[i][0] > target){
                left = i-1;
                break;
            }
        } 
        
        if(left < 0)
            return false;
        
        return bsearch(matrix[left],0,matrix[0].size()-1,target);
        
    }
};
