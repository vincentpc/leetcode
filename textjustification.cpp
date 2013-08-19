class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = words.size();
        int i = 0;
        int j;
        int t,k;   
        int count;
        int wcount;
        int space;
        int left;
        int avg;
        vector<string> result;
        string res;
        result.clear();
        
        while(i < n){
            res = "";
            count = 0;

            for(j = i; j < n; j ++){
                count += words[j].size();
                if(count > L)
                    break;
                count++;
                
            }
        
            if(j != n){

                j --;
        
                wcount = j -i+1;
                count = 0;
                
                for(t = i; t <= j; t ++){
                    count+=words[t].size();
                    
                }
                
                space = L-count;
 
                
                if(wcount == 1){
                    res+= words[i];
                }
                else{
                    avg = space/(wcount-1);
                    left = space - avg* (wcount-1);
                    
                    res+= words[i];
                    
                    for(t = i+1; t <= j; t ++){
                        
                        if(left != 0){
                            k = 1+avg;
                            while(k > 0){
                                res+= " ";
                                k--;
                            }
                            left--;
                            res+=words[t];
                        }
                        else{
                            k = avg;
                            while(k > 0){
                                res+= " ";
                                k--;
                            }
    
                            res+=words[t];                            
                        }
                    }
                  
                }
                
            }
            else{
                
                
                for(t = i; t < n; t ++){
                    res+=words[t];
                    if(t != n-1)
                        res+=" ";
                }

            }
            
            while(res.size() < L){
                res += " ";
            }            
            result.push_back(res);
            i = j+1;
            
        }
        return result;
    }
};       
