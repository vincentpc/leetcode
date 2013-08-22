class Solution {
public:
    vector<int> a;
    vector<int> b;
    
    double find(int abeg,int aend,int bbeg,int bend,int target){
        if(abeg > aend)
            return b[bbeg+target-1];
        if(bbeg > bend)
            return a[abeg+target-1];
        
        if(target <= 1)
            return min(a[abeg],b[bbeg]);
            
        
        int amid=(abeg+aend)/2;
        int bmid=(bbeg+bend)/2;
        
        if(a[amid] > b[bmid]){
            if((amid-abeg+1)+(bmid-bbeg+1) <= target){
                return find(abeg,aend,bmid+1,bend,target-(bmid-bbeg+1));
            }
            else 
                return find(abeg,amid-1,bbeg,bend,target);
     
                
                
        }
        else{
            if((amid-abeg+1)+(bmid-bbeg+1) <= target){
                return find(amid+1,aend,bbeg,bend,target-(amid-abeg+1));
            }
            else
                return find(abeg,aend,bbeg,bmid-1,target);

        }
        
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        a.clear();
        b.clear();
        
        a.push_back(0);
        for(int i = 0; i < m; i ++)
            a.push_back(A[i]);
        
        b.push_back(0);
        for(int i = 0; i < n; i ++)
            b.push_back(B[i]);
        
        if((m+n) % 2 != 0){
            return find(1,m,1,n,(m+n)/2+1);
        }
        else{
            return (find(1,m,1,n,(m+n)/2)+find(1,m,1,n,(m+n)/2+1))/2;
        }
    }
};
