/*
 * add-binary.cpp
 *
 *  Created on: 2018年7月11日
 *      Author: garvin
 */

/*Given two binary strings, return their sum (also a binary string).

For example,
a ="11"
b ="1"
Return"100". */

/*
 * 和之前相加两条链表数值的题很像
 * 需要注意最后的进位不要落下
 */

class Solution {
public:
    string addBinary(string a, string b) {
        if(a == "" && b=="")
            return "";
        if(a == "")
            return b;
        if(b == "")
            return a;
        int sizea = a.size();
        int sizeb = b.size();

        string ans = "";
        bool jinwei = false;
        while(sizea>0 && sizeb>0){
            sizea--, sizeb--;
            int sum = jinwei + a[sizea] - '0' + b[sizeb] - '0';
            jinwei = (sum>=2 ? true : false);
            ans += (sum%2 ? '1' : '0');
        }
        while(sizea>0){
            sizea--;
            int sum = jinwei + a[sizea] - '0';
            jinwei = sum/2 ? true : false;
            ans += (sum%2 ? '1' : '0');
        }
        while(sizeb>0){
            sizeb--;
            int sum = jinwei + b[sizeb] - '0';
            jinwei = sum/2 ? true : false;
            ans += (sum%2 ? '1' : '0');
        }
        if(jinwei){
            ans+='1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
