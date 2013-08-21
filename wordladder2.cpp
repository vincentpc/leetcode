vector<vector<string> > results;
    struct point{
        string s;
        int depth;
        map<string,int> r;
        
        
    };
    queue<point> q;
class Solution {
public:
    string startstr;
    string endstr;
    int count;
    
    

    
    bool test(unordered_set<string> dict){
        vector<string> res;
        point newp;
        string temp;
        while(!q.empty()){
            point nowp = q.front();
            q.pop();
            
            if(count != 0 && nowp.depth > count)
                break;
            
            if(nowp.s == endstr){
                if(count == 0){
                    count = nowp.depth;   
                    
                    res.resize(nowp.r.size());
                    map<string,int>::iterator it;
                    for(it = nowp.r.begin(); it != nowp.r.end(); it++){
                        res[it->second] = it->first;
                    }
                    results.push_back(res);  
                }
                else{
                    
                    res.resize(nowp.r.size());
                    map<string,int>::iterator it;
                    for(it = nowp.r.begin(); it != nowp.r.end(); it++){
                        res[it->second] = it->first;
                    }
                    results.push_back(res);   
                }
                continue;
            }
            
            
            
            for(int i = 0; i < nowp.s.size(); i ++){
                for(int j = 'a'; j <= 'z'; j ++){
                    temp = nowp.s;
                    
                    if(nowp.s[i] == j)
                        continue;
                    else
                        temp[i] = j;
                    
                    if(nowp.r.find(temp) == nowp.r.end()){
                    
                        if(dict.find(temp)!= dict.end()){
                            
                            newp.s = temp;
                            newp.depth = nowp.depth+1;
                            newp.r = nowp.r;
                            newp.r[temp] = nowp.r.size();
                            
                            
                            //newp.save = nowp.save;
                            //newp.save.push_back(temp);
                            q.push(newp);
                            //dict.erase(temp);
        
                        }
                    }
                }
            }
            
            

        }
        
        return false;
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        startstr = start;
        endstr = end;
        
        count = 0;
        
        while(!q.empty())
         q.pop();
         
        results.clear();
        
        point newp;
        newp.s = startstr;
        newp.depth = 1;
        newp.r[startstr] = 0;
        q.push(newp);
        

        test(dict);
    
        return results;        
    }
};

