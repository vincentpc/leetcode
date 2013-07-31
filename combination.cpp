class Solution {
public:
    vector<vector<int> > results;
    int length,size;
    void test(vector<int> result,int beg,int k){
        if(k == length){
            results.push_back(result);
            return;
        }
        
        
        for(int i = beg; i <= size; i ++){
            result.push_back(i);
            test(result,i+1,k+1);
            result.pop_back();
        }
        
        return;
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        results.clear();
        result.clear();
        
        length = k;
        size = n;
        test(result,1,0);
        return results;
    }
};
