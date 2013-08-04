class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char,int> chardict;
        int longest = 0;
        int num = 0;
        
        for(int i = 0; i < s.size(); i ++){
            if(chardict.find(s[i]) == chardict.end() ){
                num ++;
                chardict[s[i]] = i;
                if(num > longest)
                    longest = num;
            }
            else{
                
                for(int j = i - num; j < chardict[s[i]]; j ++){
                    chardict.erase(s[j]);
                }
                
                num = i - chardict[s[i]];
                chardict[s[i]] = i;
            }
        
        }
        return longest;
        
    }
};
