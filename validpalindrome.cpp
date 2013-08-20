class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string str,revstr;
        
        str = "";
        if(s.size() == 0)
            return true;
        
        int i,j;
        
        for(i = 0,j = 0; i < s.size(); i ++){
            if(s[i] >= '0' && s[i] <='9'){
                str += s[i];
            }
            else if(s[i] >= 'a' && s[i] <='z'){
                str+= s[i];
            }
            else if(s[i] >= 'A' && s[i] <='Z'){
                str += (s[i]-'A')+'a';
            }
        }
        
        revstr = str;
        reverse(revstr.begin(),revstr.end());
        if(str == revstr)
            return true;
        else
            return false;
    }
};
