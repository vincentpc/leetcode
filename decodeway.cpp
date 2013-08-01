class Solution {
public:
    int num;
    
    void test(string s, int beg){
        if(beg == s.length()){
            num++;
            return;
        }
        
        if(beg < s.length()){
            int now = s[beg]-'0';
            if(now >= 1 && now <= 9)
                test(s,beg+1);
        }
        
        if(beg < s.length() -1){
            int first = s[beg]-'0';
            
            if(first == 0)
                return;
            int now = (s[beg]-'0') * 10 + (s[beg+1]-'0');
            if(now <= 26 && now > 0)
                test(s,beg+2);
        }
        return;
        
    }
    
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        num = 0;
        
        if(s.length() == 0)
            return num;
            
        test(s,0);
        
        return num;
        
    }
};
