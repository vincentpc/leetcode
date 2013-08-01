class Solution {
public:
    
    string counting(string str){
        int n = str.length();
        int now = str[0]-'0';
        int count = 0;
        string res;
        res.clear();
        
        for(int i = 0; i < n ;i ++){
            if(str[i] - '0' == now){
                count ++;
            }
            else{
                res += (count+'0');
                res += (now +'0');
                count = 1;
                now = str[i] - '0';
            }
        }
        
        if(count > 0){
            res += (count+'0');
            res += (now +'0');
        }
        
        return res;
        
    }
    
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string res = "1";
        
        for(int i = 1; i < n; i ++){
            res = counting(res);
        }
        
        return res;
        
    }
};
