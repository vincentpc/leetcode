class Solution {
public:
    struct point{
        int y;
        int x;
        
    };
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        if(n == 0)
            return sum;
            
        stack<point> st;
        
        point beginpoint;
        beginpoint.y = A[0];
        beginpoint.x = 0;
        st.push(beginpoint);
        
        for(int i = 1; i < n; i ++){
            point now = st.top();
            if(now.y > A[i]){
               
            }
            else{
                now = st.top();
                st.pop();
                int btm = now.y;
                
                while(!st.empty()){
                    now = st.top();
                    if(now.y > A[i]){
                        sum += (A[i] - btm) * (i - now.x-1);
                        break;
                    }
                    
                    sum += (now.y - btm) * (i - now.x-1);
                    btm = now.y;
                    
                    st.pop();
                }
                
                
            }
            
            point nowpoint;
            nowpoint.y = A[i];
            nowpoint.x = i;
            st.push(nowpoint); 
                
        }
        
        return sum;
    }
};
