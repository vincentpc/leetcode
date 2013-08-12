class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        int i = 0;
        while(s[i] == 'M'){
            sum += 1000;
            i ++;
        }
        if(s[i] == 'C' && s[i+1] == 'M'){
            sum += 900;
            i += 2;
        }

        if(s[i] == 'D'){
            sum += 500;
            i ++;
        }
        
        if(s[i] == 'C' && s[i+1] == 'D'){
            sum += 400;
            i += 2;
        }
        
        while(s[i] == 'C'){
            sum += 100;
            i ++;
        }
        if(s[i] == 'X' && s[i+1] == 'C'){
            sum += 90;
            i += 2;
        }

        if(s[i] == 'L'){
            sum += 50;
            i ++;
        }
        
        if(s[i] == 'X' && s[i+1] == 'L'){
            sum += 40;
            i += 2;
        }

        while(s[i] == 'X'){
            sum += 10;
            i ++;
        }
        if(s[i] == 'I' && s[i+1] == 'X'){
            sum += 9;
            i += 2;
        }

        if(s[i] == 'V'){
            sum += 5;
            i ++;
        }
        
        if(s[i] == 'I' && s[i+1] == 'V'){
            sum += 4;
            i += 2;
        }
        while(s[i] == 'I'){
            sum += 1;
            i ++;
        }
        
        return sum;
        
    }
};
