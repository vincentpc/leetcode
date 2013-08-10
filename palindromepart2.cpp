class Solution {
public:
    int a[1500];
    bool mark[1500][1500];

    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if(s.size() == 0 || testpart(s) == true)
            return 0;
     
        

        
        a[0] = 0;
        for(int i = 0; i < s.size(); i ++){
            mark[i][1] = 1;
            mark[i][0] = 1;
        }
            
        for(int i = 2; i <= s.size(); i ++){
            for(int j = 0; i+j-1 < s.size(); j ++){
                int left = j,right = j+i-1;
                
                if(s[left] == s[right]){
                    mark[j][i] = mark[j+1][i-2];
                    
                }
                else
                    mark[j][i] = 0;
                       
                
            }
        }
        
        for(int i = 1; i < s.size(); i ++){
            if(mark[0][i+1] == 1){
                a[i] = 0;
                continue;
            }
            else{
                a[i] = i;
            }
            for(int j = 1; j <= i ; j ++){
                if(a[j-1] >= a[i]-1)
                    continue;
                //string tmpstr = s.substr(j,i-j+1);
                if(mark[j][i-j+1] == 1){
                    if(a[j-1] + 1 < a[i]){
                        a[i] = a[j-1]+1;
                    }
                }
            }
        }
        
        return a[s.size()-1];
        
    }
};
