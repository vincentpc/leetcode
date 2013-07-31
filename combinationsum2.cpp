class Solution {
public:
    vector<vector<int> > results;
    vector<int> result;
    int targetsum,size;
    vector<int> can;
    
    void test(vector<int> result,int beg,int k){
        if(k > targetsum)
            return;
            
        if(k == targetsum){
            if(find(results.begin(),results.end(),result) == results.end())
                results.push_back(result);
            return;
        }
        
        
        for(int i = beg; i < size; i ++){
            result.push_back(can[i]);
            test(result,i+1,k + can[i]);
            result.pop_back();
        }
        
        return;
    }
    
    
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        results.clear();
        sort(candidates.begin(), candidates.end());
        targetsum = target;
        size = candidates.size();
        can = candidates;
        
        result.clear();
        test(result,0,0);
        return results;
        
        
    }
};
