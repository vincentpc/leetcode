vector<vector<bool>> mark; 
       vector<bool> res;
class Solution {
public:

    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
        while(*p == '*'){
            if(*(p+1) == '*')
                p++;
            else
                break;
        }
        
        
        mark.clear();

        for(int i = 0; i <= strlen(s); i ++){
            vector<bool>().swap(res); 
            res.resize(strlen(p)+1,0);
            mark.push_back(res);
        } 
        
        mark[0][0] = 1;
        
        if(*p =='*'){
            for(int i = 0; i <= strlen(s); i ++){
                mark[i][1] = 1;
            }    
        }
        
        
        
        for(int j = 1; j <= strlen(p); j ++){
            for(int i = 1; i <= strlen(s); i++){
                mark[i][j] = 0;
                if(s[i-1] == p[j-1]){
                    mark[i][j] = mark[i-1][j-1];
                }
                else if(p[j-1] == '?'){
                    mark[i][j] = mark[i-1][j-1];

                }
                else if(p[j-1] == '*'){
                    if(j-2 >= 0 && p[j-2] == '*'){
                        mark[i][j] = mark[i][j-1];
                        
                    }
                    else{

                        if(mark[i][j-1] == 1 || mark[i-1][j] == 1 || mark[i-1][j-1] == 1){
                            mark[i][j] = 1;
                         
                        }

                        
                    }
                    
                    
                }
   
                    
            }
        }
        
        if(mark[strlen(s)][strlen(p)] == 1)
            return true;
        else
            return false;
            
        
        
    }
};
