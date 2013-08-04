class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string maxstr = "";
        int len = 0;
        for(int i = 0; i < s.size(); i ++){
            int left = i - 1,right = i+1;
            int templen = 1;
            
            while(left >= 0 && right <= s.size() -1){
                if(s[left] == s[right]){
                    left --;
                    right ++;
                    templen+=2;
                }
                else{
                    break;
                }
            }
            
            if(templen > len){
                len = templen;
                maxstr = s.substr(i - (templen-1)/2, templen);
                
            }
            
            left = i,right = i+1;
            templen = 0;
            
            while(left >= 0 && right <= s.size() -1){
                if(s[left] == s[right]){
                    left --;
                    right ++;
                    templen+=2;
                }
                else{
                    break;
                }
            }
            
            if(templen > len){
                len = templen;
                maxstr = s.substr(i - (templen-1)/2, templen);
                
            }
            
            
            
        }
        return maxstr;
    }
};
