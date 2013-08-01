
class Solution {
public:
    int num;
    int mark[100000];
    int test(string s, int beg){
        if(beg == s.length()){
            //num++;
            return 1;
        }
        
        int first = 0,second = 0;
        
        if(mark[beg] != 0)
            return mark[beg];
        
        
        if(beg < s.length()){
            int now = s[beg]-'0';
            if(now >= 1 && now <= 9)
                first = test(s,beg+1);
        }
        
        if(beg < s.length() -1){
            int now = (s[beg]-'0') * 10 + (s[beg+1]-'0');
            if(now <= 26 && now >= 10)
                second = test(s,beg+2);
        }
        
        mark[beg] = first+second;
        
        return first+second;
        
        
    }
    
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        num = 0;
        memset(mark,0,sizeof(mark));
        
        if(s.length() == 0)
            return num;
            
        test(s,0);
        
        return mark[0];
        
    }
};
