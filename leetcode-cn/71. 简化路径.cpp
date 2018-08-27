/*
 * 71. 简化路径.cpp
 *
 *  Created on: 2018年8月27日
 *      Author: garvin
 */

/*
 * 找出所有使用'/'相隔的string
 * 使用deque，若为“..”,则deque从后面弹出来一个
 * 若为".",则直接无视
 * 否则放入deque后侧
 */

/*
给定一个文档 (Unix-style) 的完全路径，请进行路径简化。

例如，
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

边界情况:

    你是否考虑了 路径 = "/../" 的情况？
    在这种情况下，你需返回 "/" 。
    此外，路径中也可能包含多个斜杠 '/' ，如 "/home//foo/" 。
    在这种情况下，你可忽略多余的斜杠，返回 "/home/foo" 。
*/


class Solution {
public:
    string simplifyPath(string path) {
        int size = path.size();
        if(size<=0)
            return path;
        deque<string> dq;
        int startindex = 0;
        bool issearching = false;
        for(int i=0; i<size; i++){
            if(path[i] == '/'){
                if(i==0 || path[i-1] == '/')
                    continue;
                if(path.substr(startindex, i-startindex) == ".."){
                    if(dq.size())
                        dq.pop_back();
                }
                else if(path.substr(startindex, i-startindex) == ".")
                    ;
                else
                    dq.push_back(path.substr(startindex, i-startindex));
                issearching = false;
            }
            else if(path[i]!='/' && (i==0 || path[i-1] == '/'))
                startindex = i, issearching = true;
        }
        if(issearching){
            if(path.substr(startindex, size-startindex) == ".."){
                if(dq.size())
                    dq.pop_back();
            }
            else if(path.substr(startindex, size-startindex) == ".")
                ;
            else
                dq.push_back(path.substr(startindex, size-startindex));
        }
        int qsize = dq.size();
        string result;
        while(!dq.empty()){
            string tmp = dq.front();
            dq.pop_front();
            result += '/';
            result += tmp;
        }
        if(result == "")
            return "/";
        return result;
    }
};


