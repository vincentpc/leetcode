class Solution {
public:
    int fib(int n){

        
        int first = 1;
        int second = 1;
        for(int i = 2; i <= n; i ++){
            int temp = first +second;
            first = second;
            second = temp;
            
        }
        return second;
    }

    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
        int result = fib(n);
        return result;
        
    }
};
