class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> s;
        
        string result = "";
        string temp = "";
        for(int i = 1; i < path.size(); i ++){
            if(path[i] =='/'){
                if(temp == "." || temp == ""){
                    
                }
                
                else if(temp == ".."){
                    if(!s.empty())
                        s.pop_back();
                }
                else
                    s.push_back(temp);
                
                temp = "";
            } 
            else{
                temp += path[i];
            }
        }
        
        if(temp == "." || temp == ""){
            
        }
        
        else if(temp == ".."){
            if(!s.empty())
                s.pop_back();
        }
        else
            s.push_back(temp);   
            
        
        for(int i = 0; i < s.size(); i ++){
            result+="/";

            result+=s[i];
            //s.pop();
            
        }
        if(result == "")
            result = "/";
            
        return result;
        
    }
};
