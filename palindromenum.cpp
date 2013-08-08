class Solution {
public:
    int get(int x,int bit){
        
        int leftten = 1;
        
        if(bit == 1)
            return x%10;
            
        for(int i = 1; i < bit; i ++){
            leftten *= 10;
            
        }
        
    
        int rightten = leftten / 10;
        
        int leftbit = x- (x%leftten);
        
        while(leftbit >= 10){
            leftbit = leftbit/10;
        }
        return leftbit;

    }

    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x < 0)
            return false;
        if(x < 10)
            return true;
        
        int n = 1;
        
        int r = 1;
        int l = 1;
        int flag = 0;
        while(x/n >= 10){
            n = n * 10;
            r++;
        }
        

        while(l < r){
            int rnum = get(x,r);
            int lnum = get(x,l);
            
            if(rnum != lnum){
                flag = 1;
                break;
            }
            
            r--;
            l++;
            
            
        }
        if(flag == 0)
            return true;
        else
            return false;
            
        
    }
};
