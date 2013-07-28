class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        vector<vector<int> > results;
        int closetarget;
        sort(num.begin(),num.end());
        int i,j,k,t;
        for(i = 0;i < n; i ++){
            for(t = i+1; t < n; t++){
                j = t + 1;
                k = n - 1;
                
                while(j < k){
                    closetarget = num[i] + num[j] + num[k] + num[t];
                    if(target == closetarget){
                        vector<int> result;
                        result.push_back(num[i]);
                        result.push_back(num[t]);
                        result.push_back(num[j]);
                        result.push_back(num[k]);
                        if(find(results.begin(),results.end(),result) == results.end())
                            results.push_back(result);
                        j ++;
                        k --;
                    }
                    
                    else if(closetarget < target)
                        j++;
                    else
                        k--;
                
                }
            }
        }
        return results;
    }
};
