/*
 * 风口的猪-中国牛市.cpp
 *
 *  Created on: 2018年8月14日
 *      Author: garvin
 */


/*风口之下，猪都能飞。当今中国股市牛市，真可谓“错过等七年”。
给你一个回顾历史的机会，已知一支股票连续n天的价格走势，以长度为n的整数数组表示，数组中第i个元素（prices[i]）代表该股票第i天的股价。
假设你一开始没有股票，但有至多两次买入1股而后卖出1股的机会，并且买入前一定要先保证手上没有股票。
若两次交易机会都放弃，收益为0。 设计算法，计算你能获得的最大收益。
输入数值范围：2<=n<=100,0<=prices[i]<=100 */

/*
 * 借鉴自股票问题中，只能抛售一次的情况
 * 将时间割裂成两部分，求两部分最大收益
 * 讨论区时间复杂度更低的方法思路为
 * 从头到尾记录抛售一次最大利润，从尾到头再记录依次最大利润，分别用两个vector记录
 * 也就是说，第一个vector中，第i项为第一天到第i天最大利润
 * 第二个vector中，第i项为i到最后一天最大利润
 * 遍历两个vector，第i项相加，求最大值即可
 */

class Solution {
public:
    /**
     * 计算你能获得的最大收益
     *
     * @param prices Prices[i]即第i天的股价
     * @return 整型
     */

    int getmax(vector<int>& prices, int start, int end){
        int Min = prices[start];
        int Max = prices[start];
        int ans = Max-Min;
        for(int i=start+1; i<=end; i++){
            if(prices[i]<Min){
                Min = prices[i];
                Max = prices[i];
            }
            if(prices[i]>Max){
                Max = prices[i];
                ans = max(ans, Max-Min);
            }
        }
        return ans;
    }

    int calculateMax(vector<int> prices) {
        int size = prices.size();
        int ans = 0;
        for(int i=1; i<=size-1; i++)
            ans = max(ans, getmax(prices, 0, i)+getmax(prices, i, size-1));
        return ans;
    }
};
