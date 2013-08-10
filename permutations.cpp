class Solution {
public:

    vector<int> next_permute(vector<int> num){
        int n = num.size();
        int i;
        
        for(i = n-1; i > 0; i --){
            if(num[i-1] < num[i]){
                int tag = num[i-1];
                int mini = 10000;
                int locate = 0;
                for(int j = i; j < n; j ++){
                    if(num[j] > tag && num[j] < mini){
                        mini = num[j];
                        locate = j;
                    }
                }
                
                swap(num[locate],num[i-1]);
                sort(num.begin()+i, num.end());
                break;
            }
        }
        
        if(i == 0)
            sort(num.begin(),num.end());
        return num;
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = 1;
        vector<vector<int> > results;
        
        if(num.size() == 0)
            return results;
            
        for(int i = 1; i <= num.size(); i ++){
            n *= i;
        }
        
        vector<int> res = num;
    
        for(int i = 0; i < n; i ++){
            results.push_back(res);        
            res = next_permute(res);
            
        }
        
        return results;
    }
};
