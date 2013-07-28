class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        map<string,vector<string> > mark;
        
        while(!strs.empty()){
            string str = strs.back();
            strs.pop_back();
            string sortstr = str;
            
            sort(sortstr.begin(),sortstr.end());
            mark[sortstr].push_back(str);
        }
        
        map<string, vector<string> >::iterator it = mark.begin();
        while(it!=mark.end()){
            vector<string> tmp = it->second;
            if(tmp.size() > 1){
                
                while(!tmp.empty()){
                    result.push_back(tmp.back());
                    tmp.pop_back();
                }
            }
            it++;
        }
        return result;
        
    }
};
