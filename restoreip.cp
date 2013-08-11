class Solution {
public:
    vector<string> results;
    string str;
    
    void test(int beg, int  num, string res){
        if(num == 4 && beg == str.size()){
            results.push_back(res);
            return;
        }
        
        if(beg > str.size())
            return;
        
        string temp = "";
        for(int i = beg; i < beg+3 && i < str.size(); i ++){
            
            temp += str[i];
            int tempnum = atoi(temp.c_str());
            if(tempnum >= 0 && tempnum <= 255){
                if(num != 3)
                    test(i+1,num+1,res+temp+".");
                else
                    test(i+1,num+1,res+temp);
            }
            if(tempnum == 0)
                break;
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        results.clear();
        if(s.size() == 0|| s.size() >12)
            return results;
        str = s;  
        string res = "";
        test(0, 0, res);
        return results;
        
    }
};
