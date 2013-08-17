class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign = 0;
        int overflow = 0;
        while(*str == ' '){
            str++;
        }
        if(*str == '-'){
            sign = 1;
            str++;
        }
        if(*str == '+'){
            sign = 0;
            str++;
            
        }
        int result = 0,count = 0;
        
        while(*str != '\0'){
            if(*str >= '0' && *str <='9'){
                result *= 10;
                result += *str - '0';
                if(result < 0)
                    overflow = 1;
            }
            else{
                break;
            }
            str++;
            count++;
        }
        
        if(overflow == 1 || count > 10){
            if(sign == 0)
                return INT_MAX;
            else
                return INT_MIN;
        }
        
        if(sign == 1)
            return -result;
        else
            return result;
            
    }
};
