class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign = 0;
        if(x < 0){
            sign = 1;
            x = -x;
        }
        
        int sum = 0;
        
        while(x > 0){
            int nowbit = x%10;
            sum *= 10;
            sum += nowbit;
            x /= 10;
        }
        
        if(sign == 1)
            sum = -sum;
        return sum;
        
    }
};
