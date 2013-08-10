class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        reverse(digits.begin(),digits.end());
        int carry = 0;
        
        if(digits.size() == 0){
            digits.push_back(1);
            return digits;
        }
        
        digits[0] += 1;
        
        for(int i = 0; i < digits.size(); i ++){
            digits[i] += carry;
            carry = digits[i] / 10;
            
            digits[i] %= 10;
            
        }
        
        if(carry != 0)
            digits.push_back(carry);
            
        reverse(digits.begin(),digits.end());
        return digits;
        
    }
};
