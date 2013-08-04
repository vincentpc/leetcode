class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = 0;
        int start = 0;
        int len = strlen(s);
        for(int i = strlen(s) - 1; i >= 0; i --){
            if(s[i] == ' ')
                len --;
            else 
                break;
        }
        
        for(int i = 0; i < len; i ++){
            if(s[i] != ' ')
                start++;
            else
                start = 0;
        }
        length = start;
        return length;
        
    }
};
