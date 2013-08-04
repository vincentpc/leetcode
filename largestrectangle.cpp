class Solution {
public:
    struct point{
        int h;
        int p;
    };
    
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int x[50000],y[50000];
        int newh;
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        
        stack<point> s;
        
        for(int i = 0; i < height.size(); i ++){
            newh = height[i];
            while(!s.empty()){
                point cmppoint = s.top();
                if(cmppoint.h >= newh){
                    s.pop();
                }
                else{
                    break;
                }
            }
            if(s.empty()){
                x[i] = 0;
            }
            else{
                x[i] = s.top().p +1;
                
            }
            
            point newpoint;
            newpoint.h = newh;
            newpoint.p = i;
            s.push(newpoint);
        }
        
        while(!s.empty())
            s.pop();
            
        for(int i = height.size()-1; i >= 0; i --){
            newh = height[i];
            while(!s.empty()){
                point cmppoint = s.top();
                if(cmppoint.h >= newh){
                    s.pop();
                }
                else{
                    break;
                }
            }
            if(s.empty()){
                y[i] = height.size() -1;
            }
            else{
                y[i] = s.top().p-1;
                
            }
            
            point newpoint;
            newpoint.h = newh;
            newpoint.p = i;
            s.push(newpoint);
        }
        
        int maxarea = 0;
        
        for(int i = 0; i < height.size(); i ++){
            int length = y[i]-x[i]+1;
            if(length * height[i] > maxarea)
                maxarea = length * height[i];
                
        }
        return maxarea;
        
    }
};
