class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> save = numbers;
        
        sort(numbers.begin(),numbers.end());
        
        vector<int> result;
        
        int left,right;
        left = 0;
        right = numbers.size() -1;
        while(left < right){
            if(numbers[left]+numbers[right] > target){
                right --;
            }
            else if(numbers[left]+numbers[right] < target){
                left ++;
            }
            else{
                left = numbers[left];
                right = numbers[right];
                break;
            }
        }
        
        for(int i = 0; i < save.size(); i ++){
            if(save[i] == left){
                result.push_back(i+1);
            }
            else if(save[i] == right){
                result.push_back(i+1);
            }
        }
        

        return result;
        
    }
};
