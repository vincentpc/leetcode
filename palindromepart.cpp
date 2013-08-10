class Solution {
public:
    vector<vector<string>> results;
    string str;
    
    bool testpart(string teststr){
        string rev = teststr;
        reverse(teststr.begin(),teststr.end());
        if(rev == teststr)
            return true;
        else
            return false;
            
    }
    void test(int start,vector<string> res){
        
        if(start == str.size()){
            results.push_back(res);
            return;
        }
        
        for(int i = start; i < str.size(); i ++){
            string teststr = str.substr(start,i-start+1);
            if(testpart(teststr)){
                res.push_back(teststr);
                test(i+1,res);
                res.pop_back();
            }
        }
        return;
    }
        
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        results.clear();
        str = s;
        
        if(s.size() == 0)
            return results;
        vector<string> res;
        test(0,res);
        return results;
    }
};
