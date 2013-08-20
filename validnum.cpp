class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int flag = 0;
        int sign = 0;
        int numsign = 0;
        int dotsign = 0;
        int esign = 0;
        
        while(*s == ' ')
            s++;
        
        if(strlen(s) == 0)
            return false;
            
        for(int i = 0; i < strlen(s); i ++){
            char now = s[i];
            
            if(numsign+sign+dotsign + esign == 0 && (now == '+' || now == '-')){
                sign = 1;
                continue;
            }
            
            if(now>= '0' && now <= '9')
                numsign = 1;
            else if(esign == 0 && dotsign == 0 && now == '.'){
                    dotsign = 1;
                    if(i+1 < strlen(s) && s[i+1] == 'e'){
                        if(numsign == 0){
                            flag = 1;
                            break;
                        }
                    }
            }
            else if(esign == 0 && (now == 'e' || now == 'E')){
                if(i-1 >= 0 && ((s[i-1]>= '0' && s[i-1] <= '9')|| s[i-1] == '.')){
                    if(i+1 < strlen(s) && ((s[i+1]>= '0' && s[i+1] <= '9')||  s[i+1]=='+'||s[i+1]=='-')){
                        i++;
                        if(s[i] == '+' || s[i] == '-'){
                            if(i+1 < strlen(s) && (s[i+1]>= '0' && s[i+1] <= '9')){
                            
                            
                            }
                            else{ 
                                flag = 1;
                                break;
                            }
                        }
                        esign = 1;    
                        
                    }
                    else{ 
                        flag = 1;
                        break;
                    }
                }
                else{
                    flag = 1;
                    break;
                }
                
            }
            
            else if(now == ' ' && numsign == 1){
                while(s[i] == ' '){
                    i++;
                }
                
                if(i == strlen(s)){
                    flag = 0;
                    break;
                }
                else{
                    flag = 1;
                    break;
                }
            }
            
            else{
                flag = 1;
                break;
            }
        }
        
        if(flag == 1 || numsign == 0)
            return false;
        else
            return true;
    }
};
