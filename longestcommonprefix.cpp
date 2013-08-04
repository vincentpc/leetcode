class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string prefix = "";
        
        if(strs.size() == 0)
            return prefix;
        
        for(int i = 0; i < strs[0].size(); i ++){
            char now = strs[0][i];
            int flag = 0;
            for(int j = 1; j < strs.size(); j ++){
                if(strs[j].size() < i+1 || strs[j][i] != now){
                    flag = 1;
                    break;
                }
                    
            }
            
            if(flag == 1)
                break;
            prefix += now;
        }
        return prefix;
        
    }
};
