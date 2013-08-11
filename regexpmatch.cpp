class Solution {
public:
    bool check;
    
    bool test(const char *s,const char *p){
        
        if(*p == '\0'){
            if(*s =='\0'){
                return true;
            
            }
            return false;
        }
        

        char pnow = *p;
        char snow = *s;
        char pnownext = *(p+1);
        
        if(pnownext == '*'){
            

            const char * point = s;
            
            if(test(s,p+2))
                return true;
            
            while(*point == pnow || pnow == '.'){
                
                if(test(point+1,p+2))
                    return true;
                
                point++;
                if(*point == '\0')
                    break;
                
            }
            
        }
        else if(*s == '\0'){
            return false;
        }
        else if(pnow == '.'){
            if(test(s+1,p+1))
                return true;
        }

        else if(pnow == snow){
            if(test(s+1,p+1))
                return true;
        }

        
        return false;
    }
    
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    

        check = test(s,p);
        return check;
    }
};
