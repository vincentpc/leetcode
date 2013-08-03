class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        
        int left = 0, right = 0;
        
        int s[500][500];
        
        memset(s,0,sizeof(s));
        
        s[0][0] = 1;
        
        if(s1.size() + s2.size() != s3.size())
            return false;
            
        for(int i = 1; i <= s1.size(); i ++){
            if(s1[i-1] == s3[i-1])
                s[i][0] = 1;
            else
                break;
                
        }

        for(int i = 1; i <= s2.size(); i ++){
            if(s2[i-1] == s3[i-1])
                s[0][i] = 1;
            else
                break;
                
        }
        
        for(int i = 1; i <= s1.size(); i ++){
            for(int j = 1; j <= s2.size(); j ++){
                if(s1[i-1] == s3[i+j-1]){
                    s[i][j] = max(s[i][j],s[i-1][j]);
                }
                
                if(s2[j-1] == s3[i+j-1]){
                    s[i][j] = max(s[i][j],s[i][j-1]);
                }
            }
        }
        
        if(s[s1.size()][s2.size()] == 1)
            return true;
        else return false;
        
        
    }
};
