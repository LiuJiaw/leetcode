/*
 * 斐波拉契加强版.cpp
 *
 *  Created on: 2018年8月15日
 *      Author: garvin
 */

/*对于斐波拉契经典问题，我们都非常熟悉，
通过递推公式F(n) = F(n - 1) + F(n - 2)，我们可以在线性时间内求出第n项F(n)，
现在考虑斐波拉契的加强版，我们要求的项数n的范围为int范围内的非负整数，
请设计一个高效算法，计算第n项F(n-1)。第一个斐波拉契数为F(0) = 1。

给定一个非负整数，请返回斐波拉契数列的第n项，为了防止溢出，请将结果Mod 1000000007。*/

/*
 * 利用递推公式
 * f(2n) = f(n)f(n) + f(n-1)f(n-1)
 * f(2n+1) = f(n)f(n+1) + f(n)f(n-1)
 * 可以将线性复杂度降低至O(lgn)
 */

class Fibonacci {
public:
    map<int, int> mp;
    int getNthNumber(int n) {
        // write code here
        if(n==0 || n==1)
            return 1;
        if(n==2)
            return 2;
        if(mp.find(n) != mp.end())
            return mp[n];
        long long int ans = 0;
        long long int a = getNthNumber(n/2+1), b = getNthNumber(n/2), c = getNthNumber(n/2-1);
        if( n%2 )
            ans = a*b + c*b;
        else
            ans = b*b + c*c;
        ans %= 1000000007;
        mp[n] = ans;
        return ans;
    }
};
