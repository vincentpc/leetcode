class Solution {
public:
    vector<string> dict;
    
    void init(){
        string str= "";
        dict.push_back(str);
        str = "";
        dict.push_back(str);
        str = "abc";
        dict.push_back(str);
        str = "def";
        dict.push_back(str);
        str = "ghi";
        dict.push_back(str);
        str = "jkl";
        dict.push_back(str);
        str = "mno";
        dict.push_back(str);
        str = "pqrs";
        dict.push_back(str);
        str = "tuv";
        dict.push_back(str);
        str = "wxyz";
        dict.push_back(str);
    }
    
    vector<string> results;
    string digit;
    
    void dfs(int beg,string result){
        if(beg == digit.size()){
            results.push_back(result);
            return;
        }
        
        int num = digit[beg]-'0';
        for(int i = 0; i < dict[num].size(); i ++){
            dfs(beg+1,result+dict[num][i]);
        }
        return;
        
        
    }
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        init();
        results.clear();
        string result;
        digit = digits;
        dfs(0,result);
        return results;
        
    }
};
