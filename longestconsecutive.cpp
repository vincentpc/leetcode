class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int,int> m;
        int longest = 0;
        
        for(int i = 0; i < num.size(); i ++){
            m[num[i]] = i;
        }
        
        for(int i = 0; i < num.size(); i ++){
            
            if(m.find(num[i]) == m.end())
                continue;
                
            int lcount = 0, rcount = 0;
            int left = num[i] -1, right = num[i] + 1;
            while(m.find(left) != m.end()){
                lcount++;
                m.erase(left);
                left --;
                
            }
            while(m.find(right) != m.end()){
                rcount++;
                m.erase(right);
                right++;
            }        
            
            if(lcount+rcount+1 > longest)
                longest = lcount+rcount+1;
            
        }
        
        return longest;
    }
};
