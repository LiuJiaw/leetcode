/*
 * best-time-to-buy-and-sell-stock.cpp
 *
 *  Created on: 2018年7月5日
 *      Author: garvin
 */

//股票问题三例

/*Say you have an array for which the i th element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit. */

//每到新的一天，记录当前最低值，并根据新的一天的价格决定是否更新最大收益

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() == 0)
            return 0;
        int size = prices.size();
        int ans = 0;
        int Min = INT_MAX;
        for(vector<int>::iterator item=prices.begin(); item!=prices.end(); item++){
            Min = min(Min, *item);
            ans = max(ans, *item-Min);
        }
        return ans;
    }
};



/*Say you have an array for which the i th element is the price of a given stock on day i.
Design an algorithm to find the maximum profit.
You may complete as many transactions as you like
(ie, buy one and sell one share of the stock multiple times).
However, you may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again). */

/*可以无限次购买，但只能持有一股
 * 最大收益为股票图所有的上扬部分，也就是可以将所有的上涨相叠加，即为所求
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if(size == 0)
            return 0;
        int ans = 0;
        for(int i=1;i<size;i++){
            if(prices[i]>prices[i-1]){
                ans+=(prices[i]-prices[i-1]);
            }
        }
        return ans;
    }
};


/*Say you have an array for which the i th element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).*/

/*
 * 两次购买股票，必须抛售第一支后方可购买第二支
 * 可以将股票价格曲线分为两个部分，分别求各部分的最优解
 * 所以只需要考虑如何取划分线即可
 * 正向求第一天到第i天最大利润（只购买一次），反向求第i天到最后一天的最大利润（同样只购买一次）
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if(size == 0)
            return 0;
        int *record1 = new int[size];
        int *record2 = new int[size];
        int min1 = INT_MAX;
        int max2 = INT_MIN;
        int ans1 = 0;
        int ans2 = 0;

        for(int i=0; i<size; i++){
            if(prices[i]<min1)
                min1 = prices[i];
            ans1 = max(ans1, prices[i]-min1);
            record1[i] = ans1;
        }
        for(int i=size-1; i>=0; i--){
            if(prices[i]>max2)
                max2 = prices[i];
            ans2 = max(ans2, max2-prices[i]);
            record2[i] = ans2;
        }

        int ans = 0;
        for(int i= 0; i<size; i++){
            ans = max(ans, record1[i]+record2[i]);
        }
        delete record1;
        delete record2;
        return ans;
    }
};

