class Solution {
public:
    string startstr;
    string endstr;
    int count;
    
    struct point{
        string s;
        int depth;
    };
    queue<point> q;
    
    bool test(unordered_set<string> dict){

        while(!q.empty()){
            point nowp = q.front();
            q.pop();
            
            if(nowp.s == endstr){
                count = nowp.depth;
                return true;
            }
            
            string temp;
            
            for(int i = 0; i < nowp.s.size(); i ++){
                for(int j = 'a'; j <= 'z'; j ++){
                    temp = nowp.s;
                    
                    if(nowp.s[i] == j)
                        continue;
                    else
                        temp[i] = j;
                    
                    if(dict.find(temp)!= dict.end()){
                        point newp;
                        newp.s = temp;
                        newp.depth = nowp.depth+1;
                        q.push(newp);
                        dict.erase(temp);
    
                    }
                }
            }
            
            

        }
        
        return false;
    }
    
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        startstr = start;
        endstr = end;
        
        count = 0;
        
        while(!q.empty())
         q.pop();
         
        point newp;
        newp.s = startstr;
        newp.depth = 1;
        q.push(newp);
        

        test(dict);
    
        return count;
        
    }
};
