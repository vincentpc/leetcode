class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        int target = 0;
        vector<vector<int> > results;
        int closetarget;
        sort(num.begin(),num.end());
        int i,j,k;
        for(i = 0;i < n; i ++){
            
            j = i + 1;
            k = n - 1;
            
            while(j < k){
                closetarget = num[i] + num[j] + num[k];
                if(target == closetarget){
                    vector<int> result;
                    result.push_back(num[i]);
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
        return results;
    }
};

