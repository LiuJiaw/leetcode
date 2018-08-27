/*
 * 57. 插入区间.cpp
 *
 *  Created on: 2018年8月27日
 *      Author: garvin
 */

/*
给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1:

输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
输出: [[1,5],[6,9]]

示例 2:

输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出: [[1,2],[3,10],[12,16]]
解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
*/

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
    int getloc(vector<Interval>& intervals, int num){
        int size = intervals.size();
        int start = 0, end = intervals.size()-1;
        int middle = 0;
        if(size<=0 || num<intervals[0].start)
            return -1;
        if(num>intervals[size-1].end)
            return size;
        while(start <= end){
            middle = start + (end-start)/2;
            if(intervals[middle].start<=num && intervals[middle].end>=num || intervals[middle].end<num && intervals[middle+1].start>num)
                break;
            else if(intervals[middle].start>num)
                end = middle-1;
            else
                start = middle+1;
        }
        return middle;
    }
    vector<Interval> insert(vector<Interval>& intervals_, Interval newInterval) {
        vector<Interval> intervals(intervals_);
        int size = intervals.size();
        int startloc = 0, endloc = 0;
        startloc = getloc(intervals, newInterval.start);
        endloc = getloc(intervals, newInterval.end);
        int startnum = 0, endnum= 0;
        if(startloc<0){
            startnum = newInterval.start;
            startloc = 0;
        }
        else if(startloc>=size){
            startnum = newInterval.start;
        }
        else{
            if(intervals[startloc].end<newInterval.start)
                startnum = newInterval.start, startloc++;
            else
                startnum = intervals[startloc].start;
        }
        if(endloc>=size){
            endnum = newInterval.end;
        }
        else if(endloc<0){
            endnum = newInterval.end;
            endloc = 0;
        }
        else{
            if(intervals[endloc].end<newInterval.end)
                endnum = newInterval.end, endloc++;
            else
                endnum = intervals[endloc].end, endloc++;
        }
        intervals.erase(intervals.begin()+startloc, intervals.begin()+endloc);
        intervals.insert(intervals.begin()+startloc, Interval(startnum, endnum));
        return intervals;
    }
};


