class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> st;
        
        for(int i = 0; i < s.size(); i ++){
            
            if(s[i] == ')'){
                if(!st.empty()){
                    if(st.top() == '(')
                        st.pop();
                    else 
                        return false;
                }
                else
                    return false;
            }

            else if(s[i] == ']'){
                if(!st.empty()){
                    if(st.top() == '[')
                        st.pop();
                    else 
                        return false;
                }
                else
                    return false;
            }
            
            else if(s[i] == '}'){
                if(!st.empty()){
                    if(st.top() == '{')
                        st.pop();
                    else 
                        return false;
                }
                else
                    return false;
            }
            
            else
                st.push(s[i]);
            
        }
        
        if(st.empty())
            return true;
        else
            return false;
            
    }
};
