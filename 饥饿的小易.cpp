/*
 * 饥饿的小易.cpp
 *
 *  Created on: 2018年8月5日
 *      Author: garvin
 */

/*小易总是感觉饥饿，所以作为章鱼的小易经常出去寻找贝壳吃。
最开始小易在一个初始位置x_0。对于小易所处的当前位置x，他只能通过神秘的力量移动到 4 * x + 3或者8 * x + 7。
因为使用神秘力量要耗费太多体力，所以它只能使用神秘力量最多100,000次。
贝壳总生长在能被1,000,000,007整除的位置(比如：位置0，位置1,000,000,007，位置2,000,000,014等)。
小易需要你帮忙计算最少需要使用多少次神秘力量就能吃到贝壳。 */

/*
 * 一开始以为8x+3 是 4x+3 的两倍，但验算一下发现并不是
 * 但我们仍可以分解最小步数为2x+1
 * 其中4x+3 = 2*(2x+1)+1 ,  8x+7 = 2*( 2*(2x+1)+1  ) +1
 * 所以4x+3为2x+1的两步， 8x+7为2x+1的3步
 * 求得2x+1的最小步数即可
 */

#include <iostream>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int main() {
    int count = 0;
    long long int x_0;
    cin>>x_0;
    while( (x_0=x_0%1000000007) && count<300000 || count == 1){
        count++;
        x_0 = x_0*2+1;
    }
    int ans = 0;
    if(count == 300000)
        ans = -1;
    else if(count%3 == 0)
        ans = count/3;
    else if(count%3 == 1)
        ans = (count-4)/3 +2;
    else if(count%3 == 2)
        ans = (count-2)/3 +1;
    cout<<ans;
    return 0;
}
