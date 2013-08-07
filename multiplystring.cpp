class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        int result[300];
        string res="";
        
        memset(result,0,sizeof(result));
        
        for(int i = 0; i < num1.size(); i ++){
            for(int j = 0; j < num2.size(); j ++){
                result[i+j] += (num1[i]-'0') * (num2[j]-'0');
            }
        }
        
        int carry = 0;
        for(int i = 0; i < 300; i ++){
            result[i] += carry;
            
            carry = result[i] / 10;
            result[i] = result[i]%10;    
        }
        int beg= 0;
        for(int i = 299; i >= 0; i --){
            if(result[i] != 0){
                beg = i;
                break;
            }
        }
        
        
        
        for(int i = 0; i <= beg; i ++){
            res += result[i] +'0';
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};
