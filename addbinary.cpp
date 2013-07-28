class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result;
        result.clear();
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i = 0,j = 0,k =0;
        int carry = 0;
        while(i < a.length()|| j < b.length()){
            
            int nowbit = 0;
            if(i < a.length() && j < b.length()){
                nowbit = (a[i]-'0') + (b[j]-'0') + carry;
                if(nowbit > 1){
                    carry= 1;
                    nowbit-=2;   
                }
                else
                    carry = 0;
                result+=nowbit+'0';
                i++;
                j++;
            }
            
            else if(i < a.length()){
                nowbit = (a[i]-'0') + carry;
                if(nowbit > 1){
                    carry = 1;
                    nowbit -= 2;   
                }
                else
                    carry = 0;
                result+=nowbit+'0';
                i++;
            }
            else if(j < b.length()){
                nowbit = (b[j]-'0') + carry;
                if(nowbit > 1){
                    carry = 1;
                    nowbit -= 2;   
                }
                else
                    carry = 0;
                result+=nowbit+'0';
                j++;
            }
                        
        }

        if(carry > 0)
            result += carry+'0';
            
        reverse(result.begin(),result.end());
        return result;
        
    }
};
