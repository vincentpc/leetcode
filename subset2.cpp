class Solution {
public:
    vector<vector<int> > results;
    int n;
    vector<int> s;
    void test(vector<int> res, int begin){
        if(begin == n){
            if(find(results.begin(),results.end(), res) == results.end())
                results.push_back(res);
            return;
        }
        
        test(res,begin+1);
        res.push_back(s[begin]);
        test(res,begin+1);
        return;
        
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        results.clear();
        
        if(S.size() == 0){
            return results;
        }
        
        n = S.size();
        s = S;
        
        vector<int> result;
        sort(s.begin(),s.end());
        
        test(result,0);
        
        return results;
        
    }
};
