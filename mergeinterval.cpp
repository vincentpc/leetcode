/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
    bool cmpare(const Interval& i ,const Interval& j){
        return i.start < j.start;
    }

class Solution {
public:

    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> result;
        if(intervals.size() == 0)
            return result;
        
        sort(intervals.begin(),intervals.end(),cmpare);        
        int left = intervals[0].start;
        int right = intervals[0].end;
        
        for(int i = 1; i < intervals.size(); i ++){
            int l = intervals[i].start;
            if(l <= right){
                right = max(right,intervals[i].end);
            }
            else{
                result.push_back(Interval(left,right));
                left = intervals[i].start;
                right = intervals[i].end;
                
                
                
            }
        }
        result.push_back(Interval(left,right));

        return result;
        
    }
};
