
class Solution {
public:

    vector<int> next_permute(vector<int> num){
        int n = num.size();
        int i;
        
        for(i = n-1; i > 0; i --){
            if(num[i-1] < num[i]){
                int tag = num[i-1];
                int mini = 10000;
                int locate = 0;
                for(int j = i; j < n; j ++){
                    if(num[j] > tag && num[j] < mini){
                        mini = num[j];
                        locate = j;
                    }
                }
                
                swap(num[locate],num[i-1]);
                sort(num.begin()+i, num.end());
                break;
            }
        }
        
        if(i == 0)
            sort(num.begin(),num.end());
        return num;
    }
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> num;
        string str = "";
        int sum = 1;
        int smallsum = 1,divide = n;
        
        
        if(n == 0)
            return str;
        
        for(int i = 1; i <= n; i ++){
            num.push_back(i);
            sum *= i;
        }
        
        vector<int> res;
        
        k--;
        
        k = k % sum;
        
        for(int i = n; i > 0; i --){
            sum /= i;
            int hook= k/(sum);
            str+=num[hook]+'0';
            num.erase(num.begin()+hook);
            
            k = k%sum;
            
            
        }
        

        return str;
    }
};
