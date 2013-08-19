class Solution {
public:
    int count;
    
    int test(int left,int right){
        
        int sum = 0;
        if(left > right)
            return 1;
        
        if(left == right)
            return 1;
            
        for(int i = left; i <= right; i ++){
            
            sum += test(left,i-1) * test(i+1,right);
            
        }
        
        return sum;    
    }
    
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        count = 0;
        count = test(1,n);
        
        return count;
    }
};
