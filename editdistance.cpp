class Solution {
public:
    int a[1000][1000];
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //memset(a,0,sizeof(a));
        
        a[0][0] = 0;
        for(int i = 1; i <= word1.size(); i ++){
            a[i][0] = i;
        }
        for(int i = 1; i <= word2.size(); i ++){
            a[0][i] = i;
        }        
        
        for(int i = 1; i <= word1.size(); i ++){
            for(int j = 1; j <= word2.size(); j ++){
                
                if(word1[i-1] == word2[j-1]){
                    a[i][j] = a[i-1][j-1];
                }
                else{
                    if(a[i-1][j] > a[i][j-1])
                        a[i][j] = a[i][j-1] +1;
                    else
                        a[i][j] = a[i-1][j] +1;
                        
                    if(a[i][j] > a[i-1][j-1] +1)
                        a[i][j] = a[i-1][j-1] + 1;
                }
            }
        }
        
        return a[word1.size()][word2.size()];
        
    }
};
