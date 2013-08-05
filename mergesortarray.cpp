class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *temp =  new int[m];
        memcpy(temp,A,sizeof(int) * m);
        int k = 0,i = 0,j = 0;
        if(m == 0){
            memcpy(A,B,sizeof(int) * n);
            return;
        }
        while(i < m || j < n){
            
            if(i < m && j < n){
                if(temp[i] > B[j]){
                    A[k++] = B[j++];
                }
                else{
                    A[k++] = temp[i++];
                }
            }
            
            if(i == m && j < n){
                while(j < n)
                    A[k++] = B[j++];
            }
        
            if(j == n && i < m){
                while(i < m)
                    A[k++] = temp[i++];
            }
        }
        delete temp;
        
    }
};
