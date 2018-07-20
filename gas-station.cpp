/*
 * gas-station.cpp
 *
 *  Created on: 2018年7月20日
 *      Author: garvin
 */

/* There are N gas stations along a circular route, where the amount of gas at station i isgas[i].
You have a car with an unlimited gas tank and it costscost[i]of gas to travel from station i to its next station (i+1).
You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
Note:
The solution is guaranteed to be unique. */

/*
 * 从第一站开始，累加gas和cost的差值
 * 并记录累加和的最小值时的下标
 * 若最后一站的累加和不小于0，则说明可完成循环
 * 此时返回最小值下一个下表即可，注意取余
 */

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sizeg = gas.size();
        int sizec = cost.size();
        if(sizeg<=0 || sizec<=0 || sizeg!=sizec)
            return -1;
        int Index = -1, record = 0, Min = INT_MAX;
        for(int i=0; i<sizeg; i++){
            record+=(gas[i]-cost[i]);
            if(Min>record){
                Index = i;
                Min = record;
            }
        }
        if(record<0)
            return -1;
        return (Index+1)%sizeg;
    }
};
