class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int mini = 100000,i,r;
        
        for(i = num.size() - 1; i > 0; i --){
            if(num[i] > num[i-1]){
                int target = i-1;
                mini = 100000;
                
                for(int j = target+1; j < num.size(); j ++){
                    if(num[j] > num[target] && num[j] < mini){
                        mini = num[j];
                        r = j;
                    }
                }
                
                
                swap(num[target],num[r]);
                
                sort(num.begin() + i,num.end());
                break;
            }
        }
        
        if(i == 0){
            sort(num.begin(),num.end());
            return;
            
        }
    }
};
