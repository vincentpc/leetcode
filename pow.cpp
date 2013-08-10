class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
            return 1;
        if(abs(x-1) < 0.000001)
            return 1;
            
        if(n % 2 == 0 && x < 0){
            x = -x;
        }
        
        if(n < 0){
            return pow(1/x,-n);
        }
        
        if(n == 1)
            return x;

        if(n == 2)
            return x*x;
        
        if(x < 0.0001 && x > -0.0001)
            return 0;
        

        
        if(n % 2 == 0){
            if(x > 0)
                return pow(x,n/2) * pow(x,n/2);
            else
                return pow(-x,n/2) * pow(-x,n/2);
        }
        else{
            if(x > 0)
                return pow(x,(n-1)/2) * pow(x,(n-1)/2) * x;
            else
                return pow(-x,(n-1)/2) * pow(-x,(n-1)/2) * x;
        }
    }
};
