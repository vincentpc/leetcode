

class Solution {
public:
    int results;
    int sum;
    int cross[30],rcross[30],col[30];
    void trye(vector<int> res, int num){
        
        if(res.size() == sum){
            results++;
            return;
        
        }
        
        for(int j = 0; j < sum; j ++){
            if(col[j] == 0 && cross[num-j+sum] == 0 && rcross[num+j] == 0){
                col[j]=1;
                cross[num-j+sum] = 1;
                rcross[num+j] = 1;
                res.push_back(j);
                trye(res,num+1);
                
                col[j]=0;
                cross[num-j+sum] = 0;
                rcross[num+j] = 0;
                res.pop_back();
                
            }
        }

        return;
        
    }
    
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        results = 0;
        if(n == 0)
            return results;
            
        vector<int> res;
        

        sum = n;
        memset(cross,0,sizeof(cross));
        memset(rcross,0,sizeof(rcross));
        memset(col,0,sizeof(col));
        
        for(int i = 0; i < n; i ++){
            res.clear();
            res.push_back(i);
            
            cross[0-i+n] = 1;
            rcross[i+0] = 1;
            col[i] = 1;
            trye(res,1);

            cross[0-i+n] = 0;
            rcross[i+0] = 0;
            col[i] = 0;
            res.pop_back();
        }
        return results;
        
    }
};
