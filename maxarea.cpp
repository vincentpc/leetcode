class Solution {
public:

    
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = height.size();
        int maxsum,left,leftx;
        maxsum = 0;
        if(n < 2)
            return maxsum;
        
        int i= 0, j = n-1;
        while(i < j){
            int h = min(height[i],height[j]);
            int w = j - i;
            
            int area = h * w;
            if(area > maxsum)
                maxsum = area;
            
            int l = height[i];
            int r = height[j];
            if(l < r){
                while(height[i] <= h && i < n)
                    i++;
            }
            else{
                while(height[j] <= h && j >= 0)
                    j--;
            }
            
        }
        
        return maxsum;
    }
};
