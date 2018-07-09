/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval>answer;
    bool newIntervalAdded=false;
    int i=0, maxi = (int)intervals.size();
    while(i < maxi){
        if(newIntervalAdded){
            answer.push_back(intervals[i]);
            i++;
        } else {
            if((newInterval.start >= intervals[i].start and newInterval.start <= intervals[i].end)
                or (newInterval.end >= intervals[i].start and newInterval.end <= intervals[i].end)
                or (intervals[i].start >= newInterval.start and intervals[i].start <= newInterval.end)
                or (intervals[i].end >= newInterval.start and intervals[i].end <= newInterval.end)
               ){
                newInterval.start=min(newInterval.start, intervals[i].start);
                newInterval.end=max(newInterval.end, intervals[i].end);
                i++;
            } else if(intervals[i].end < newInterval.start){
                answer.push_back(intervals[i]);
                i++;
            } else if(intervals[i].start > newInterval.end){
                answer.push_back(newInterval);
                newIntervalAdded = true;
            }
        }
    }
    if(!newIntervalAdded)
        answer.push_back(newInterval);
    return answer;
}
