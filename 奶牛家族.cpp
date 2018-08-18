/*
 * 奶牛家族.cpp
 *
 *  Created on: 2018年8月18日
 *      Author: garvin
 */

/*在农场中，奶牛家族是一个非常庞大的家族，
对于家族中的母牛，从它出生那年算起，第三年便能成熟，成熟的母牛每年可以生出一只小母牛。
即母牛从出生开始的第三年便能做妈妈。最开始农场只有一只母牛，它从第二年开始生小母牛。
请设计一个高效算法，返回第n年的母牛总数，已知n的范围为int范围内的正整数。
给定一个正整数n，请返回第n年的母牛总数，为了防止溢出，请将结果Mod 1000000007。*/

class Cows {
public:
    void Multiply(long a[3][3],long b[3][3])
    {
        long res[3][3]={0};
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    res[i][j]+=a[i][k]*b[k][j]%1000000007;
                    res[i][j]%=1000000007;
                }
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                a[i][j]=res[i][j];
        }
    }
    int countSum(int n) {
        if(n<4)
            return n;
        long res[3][3]={3,2,1,0,0,0,0,0,0};
        long base[3][3]={1,1,0,0,0,1,1,0,0};
        n-=3;
        while(n)
        {
            if(n%2)
            {
                Multiply(res,base);
            }
            Multiply(base,base);
            n/=2;
        }
        return (int)res[0][0]%1000000007;
    }
};
