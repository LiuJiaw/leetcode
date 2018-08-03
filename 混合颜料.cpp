/*
你就是一个画家！你现在想绘制一幅画，但是你现在没有足够颜色的颜料。
为了让问题简单，我们用正整数表示不同颜色的颜料。
你知道这幅画需要的n种颜色的颜料，你现在可以去商店购买一些颜料，
但是商店不能保证能供应所有颜色的颜料，所以你需要自己混合一些颜料。
混合两种不一样的颜色A和颜色B颜料可以产生(A XOR B)这种颜色的颜料(新产生的颜料也可以用作继续混合产生新的颜色,
XOR表示异或操作)。本着勤俭节约的精神，你想购买更少的颜料就满足要求，
所以兼职程序员的你需要编程来计算出最少需要购买几种颜色的颜料？ */


#include <iostream>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *x = new int[55];
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = n - 1; i > 0; --i) {
        int maxindex = 0;
        for(int j = 1; j<=i; j++){
            if(x[maxindex] < x[j])
                maxindex = j;
            int tmp = x[maxindex];
            x[maxindex] = x[i];
            x[i] = tmp;
        }
        for (int j = i - 1; j >= 0; --j)
            if ((x[i] ^ x[j]) < x[j])
                x[j] ^= x[i];
    }
    int count0 = 0;
    for (int i = 0; x[i] == 0; i++)
        count0++;
    cout << n - count0;
    return 0;
}
