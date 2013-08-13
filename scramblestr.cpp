class Solution {
public:
        bool samecheck(string left,string right){
        if(left.length() != right.length())
            return false;
            
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        
        if(left == right)
            return true;
        else return false;
        
    }
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(s1.size() != s2.size() )
            return false;
            
        if(s1.size() == 0)
            return true;
            
        if(s1.size() == 1){
            if(s1[0] == s2[0])
                return true;
            return false;
        }
        if(s1.size() == 2){
            if(s1[0] == s2[0] && s1[1] == s2[1])
                return true;
            if(s1[0] == s2[1] && s1[1] == s2[0])
                return true;        
            return false;
        }
        
        if(samecheck(s1,s2) == false)
            return false;
        
        int mid;
        for(mid = 1; mid <= s1.size()-1; mid ++){
 
            string sub11 = s1.substr(0,mid);
            string sub12 = s1.substr(mid,s1.size() - mid);
            string sub21 = s2.substr(0,mid);
            string sub22 = s2.substr(mid,s2.size() - mid);        
            if(isScramble(sub11,sub21) && isScramble(sub12,sub22))
                return true;

            sub21 = s2.substr(0,s1.size() - mid);
            sub22 = s2.substr(s1.size() - mid,mid);        
            if(isScramble(sub12,sub21) && isScramble(sub11,sub22))
                return true;
                
        }
        return false;
    }
};
