class Solution {
public:

        vector<vector<string>> results;
        vector<int> path;
        
    void genpath(int v1, int v2, vector<string> &vdict, vector<vector<int> >& prev, 
             vector<int> res){
        
        res.push_back(v2);
        
        if(v1 == v2){
            vector<string> result;
            for(int i = res.size() -1; i >= 0; i --){
                result.push_back(vdict[res[i]]);
            }
            results.push_back(result);
            return;
            
        }
        
        vector<int> adj = prev[v2];
        
        for(int i = 0; i < adj.size(); i ++){
            genpath(v1,adj[i],vdict,prev,res);
        }
        
        res.pop_back();
        return;
        
        
                 
    }
                 
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    
        dict.insert(start);
        dict.insert(end);
         
        vector<string> vdict(dict.begin(), dict.end()); // vector dictionary: id -> word mapping in dict
        unordered_map<string, int> ids;  // index dictionary: word -> id mapping in vdict
        vector<vector<int> > prev(dict.size()); // store the previous words in BFS
        vector<int> distance(dict.size(), -1); // store the distance from start
         
        // build string - index mapping, transfer problem to graph search
        // use interger instead of string to eliminate cost of string matching
        for(int i = 0; i < vdict.size(); i++)
            ids[vdict[i]] = i;        

        
        // find the index of start and end words
        int vbeg=0, vend=0;
        while(vdict[vbeg] != start) vbeg++;
        while(vdict[vend] != end) vend++;
         
        // use queue for BFS to search path from start to end
        queue<int> que;
        que.push(vbeg);
        distance[vbeg]=0;
        
        while(!que.empty()){
            int now =  que.front();
            que.pop();
            
            if(now == vend){
                break;
            }
            
            int d = distance[now]+1;
            
            vector<int> adj;
            ids.erase(vdict[now]);
            
            for(int i = 0; i < vdict[now].size(); i ++){
                char w = vdict[now][i];
                for(char j = 'a'; j <= 'z'; j ++){
                    vdict[now][i] = j;
                    if(ids.count(vdict[now])){
                        adj.push_back(ids[vdict[now]]);
                    }
                    vdict[now][i] = w;
                }
            }
            
            
            for(int i = 0; i < adj.size(); i ++){
                if(distance[adj[i]] == -1){
                    distance[adj[i]] = d;
                    que.push(adj[i]);
                    prev[adj[i]].push_back(now);
                    
                }
                else if(distance[adj[i]] == d){
                    prev[adj[i]].push_back(now);
                }
            }
            
        }
        

        results.clear();
        path.clear();
        genpath(vbeg, vend, vdict, prev, path);
        return results;
        
    }
};
