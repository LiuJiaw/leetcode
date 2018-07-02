/*
 * evaluate-reverse-polish-notation.cpp
 *
 *  Created on: 2018年7月2日
 *      Author: garvin
 */

//Evaluate the value of an arithmetic expression in Reverse Polish Notation.

//Valid operators are+,-,*,/. Each operand may be an integer or another expression.

//Some examples:
// ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
// ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


class Solution {
public:
    int evalRPN(vector<string> &token) {
        if(token.size()==0)
            return 0;
        int length=token.size();
        int num1=0, num2=0;
        stack<int> S;
        for(int i=0;i<length;i++)
        {
            if(token[i]=="+" || token[i]=="-" || token[i]=="*" || token[i]=="/")
            {
                num1=S.top();
                S.pop();
                num2=S.top();
                S.pop();
                if(token[i]=="+") S.push(num1+num2);
                else if(token[i]=="-") S.push(num2-num1);
                else if(token[i]=="*") S.push(num1*num2);
                else S.push(num2/num1);
            }
            else
                S.push( atoi(token[i].c_str()) );
        }
        return S.top();
    }
};
