class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int longest = 0;
        stack<int> st;
        
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '('){
                st.push(1);
            }
            if(s[i] == ')'){
                if(!st.empty() && st.top() != 0){
                    if(st.top() == 1){
                        st.pop();
                        int tempsum = 2;
                        while(!st.empty() && st.top() > 1){
                            tempsum+=st.top();
                            st.pop();
                        }
                        st.push(tempsum);
                        if(tempsum > longest)
                            longest = tempsum; 
                    }
                    else{
                        int tempsum = st.top();
                        st.pop();
                        if(!st.empty() && st.top() == 1){
                            tempsum += 2;
                            st.pop();
                            while(!st.empty() && st.top() > 1){
                                tempsum+=st.top();
                                st.pop();
                            }
                            st.push(tempsum);
                            if(tempsum > longest)
                                longest = tempsum; 
                        }
                        else{
                            st.push(tempsum);
                            st.push(0);
                        }
                    }
 
                }
                else{
                    st.push(0);
                }
            }
        }
        
        return longest;
    }
};
