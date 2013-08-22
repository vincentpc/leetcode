class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int mark[500];
        int acc[500];
        int count,left=0,right;
        string result = "";
        
        memset(mark,0,sizeof(mark));
        memset(acc,0,sizeof(acc));
        
        count = T.size();
        
        for(int i = 0; i < T.size(); i ++){
            mark[T[i]] ++;
            acc[T[i]] ++;

        }
        
        
        for(int i = 0; i < S.size(); i ++){
            if(acc[S[i]] == 0){
                continue;
            }
            else{   
                if(mark[S[i]] > 0){
                    count--;
                    
                }
                mark[S[i]] --;
                
                if(count == 0){
                    
                    while(left < S.size()){
                        if(acc[S[left]] == 0){
                            left++;
                        }
                        else{
                        
                            if(mark[S[left]] >= 0)
                                break;
                            
                            else if(mark[S[left]] < 0){
                                mark[S[left]]++;
                                left++;
                            }
                            
                        }
                    }
                        
                    
                    int len = i-left+1;
                    if(result.size() == 0 || len < result.size()){
                        result = S.substr(left,len);
                    } 
                    
                    while(left<= i){
                        if(acc[S[left]] > 0){
                            mark[S[left]] ++;
                            count ++;
                            left++;
                            break;
                        }
                        left++;
                    }
                }
                
            }

        }
        return result;
        
    }
};
