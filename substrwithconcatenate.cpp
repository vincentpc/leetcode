class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        int n = L.size();
        if(n == 0)
            return result;
        
        int len = n * L[0].size();
        int slen = L[0].size();
        map<string,int> savemark,mark;

        for(int i = 0; i < n; i ++){
                savemark[L[i]] ++;
        }
        
        string temp;
        for(int i = 0; i + len <= S.size(); i ++){
            int j;
            mark.clear();
            
            
            for(j = 0; j < n; j ++){
                
                temp = S.substr(i+slen*j,slen);
                
                mark[temp]++;
                if(mark[temp] > savemark[temp])
                    break;
    

            }
            if(j == n){
                result.push_back(i);
                i = i + L[0].size()-1;
            }
        }
        return result;
    }
};
