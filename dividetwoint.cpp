class Solution {
public:
    int mark[11];
    int left[11];
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int sign = 0;
        int flag = 0;
        if(dividend < 0 && divisor > 0){
            dividend = -dividend;
            sign = 1;
        }
        
        if(dividend > 0 && divisor < 0){
            divisor = -divisor;
            sign = 1;
        }
        
        if(dividend < 0 && divisor < 0){
            dividend = -dividend;
            divisor = -divisor;
            
        }        
        
        if(dividend < 0){
            dividend = INT_MAX;
            flag = 1;
            if(divisor < 0){
                return 1;
            }
        }
        
        if(divisor < 0){
            return 0;
        }
        
        mark[0] = divisor;
        left[0] = 1;
        
        int i;
        int quot = 0,count = dividend;
        for(i = 1; i <= 10; i ++){
            
            mark[i] = mark[i-1]+mark[i-1];
            left[i] = left[i-1]+left[i-1];
            
            if(mark[i] < 0)
                break;
        }
        
        i--;
        
        for(; i >= 0; i --){
            while(count >= mark[i]){
                count-=mark[i];
                quot+= left[i];
                
                if(flag == 1){
                    count++;
                    flag = 0;
                }
            }
        }
        
        if(sign == 1)
            return -quot;
        else
            return quot;
        
        
    }
};
