/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int right,left;
        vector<Interval> result;
        int mark = 0;
        
        if(intervals.size() == 0){
            result.push_back(newInterval);
            return result;
        }

        
        vector<Interval>::iterator it = intervals.begin();
        int n = intervals.size();
        
    
        for(int i = 0; i < n-1; i ++){
            if(intervals[i].start <= newInterval.start && intervals[i+1].start > newInterval.start){
                
                intervals.insert(it+i+1,newInterval);
                mark = 1;
                break;
            }
            
        }
        if(mark == 0){
            if(intervals[0].start > newInterval.start)
                intervals.insert(it,newInterval);
            else 
                intervals.push_back(newInterval);
            
        }
        left = intervals[0].start;
        right = intervals[0].end;        
        for(int i = 1; i < intervals.size(); i ++){
            
    
            
            int l = intervals[i].start,r = intervals[i].end;
            

            if(right < l){
                result.push_back(Interval(left,right));
                left = l;
                right = r;
                
            }
            else{
                right = max(right,r);
                
            }
        }
        
        result.push_back(Interval(left,right));
        return result;
        
    }
};
