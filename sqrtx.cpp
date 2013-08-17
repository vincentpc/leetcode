class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double start = 3;
        double next;

        while(1){
            next = (start + x/start)/2;
            
            if(abs(next-start) < 0.0001)
                break;
            start = next;
        }
        return next;
            
    }
};
