class Solution {
public:
    vector<string> results;
    int size;
    void gen(string result,int left, int right){
        
        if(right == size){
            results.push_back(result);
            return;
        }
        
        string tmp;
        
        if(left < size){
            tmp = result+"(";
            gen(tmp,left+1,right);
        }
        
        if(right < left){
            tmp = result+")";
            gen(tmp,left,right+1);
        }
        
        return;
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        results.clear();
        size = n;
        
        if(n == 0)
            return results;
            
        string result="(";
        gen(result,1,0);
        return results;
        
    }
};
