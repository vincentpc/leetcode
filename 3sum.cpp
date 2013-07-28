class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        int close = -1000000,closetarget;
        sort(num.begin(),num.end());
        int i,j,k;
        for(i = 0;i < n; i ++){
            
            j = i + 1;
            k = n - 1;
            
            while(j < k){
                closetarget = num[i] + num[j] + num[k];
                if(abs(closetarget-target) < abs(close-target)){
                    close = closetarget;
                }
                
                if(closetarget < target)
                    j++;
                else
                    k--;
            
            }
        }
        return close;
        
    }
};
