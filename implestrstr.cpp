class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        /*
        unsigned int B[500];
        memset(B,0,sizeof(B));
        int i = 0;
        
        if(needle[0] == '\0')
            return haystack;
            
        for(i = 0; needle[i] != '\0' ; i ++){
            B[needle[i]] = B[needle[i]] | (1<<i);
        }
        int nlength = i;
        
        int D = 0;
        for(i = 0; haystack[i] != '\0'; i ++){
            D = ((D << 1) | 1 ) & B[haystack[i]];
            if(D & (1 << (nlength -1)))
                return &haystack[i-nlength+1];
        }
        return NULL;
        */
        
        int i,j,k;
        int count = 0;
        if(needle[0] == '\0')
            return &haystack[0];
        
        if(strlen(haystack) < strlen(needle))
            return NULL;
            
        for(i = 0; i< strlen(haystack) - strlen(needle) +1 ; i ++){
            
                for(k = 0; needle[k] !='\0';k ++){
                    if(needle[k] != haystack[i+k])
                        break;
                    else 
                        count++;
                }
                if(needle[k] == '\0')
                    return &haystack[i];
        }
        
        return NULL;
        
    }
};
