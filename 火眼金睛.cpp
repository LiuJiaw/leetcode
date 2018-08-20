/*
 * 火眼金睛.cpp
 *
 *  Created on: 2018年8月20日
 *      Author: garvin
 */

/*现在我们需要查出一些作弊的问答社区中的ID，
作弊有两种：
1.A回答了B的问题，同时B回答了A的问题。那么A和B都是作弊。
2.作弊ID用户A和作弊ID用户B同时回答了C的问题，那么C也是作弊。
已知每个用户的ID是一串数字，一个问题可能有多个人回答。

输入描述:
每组数据第一行为总问题数N(N小于等于200000)，第二行开始每行一个问题，第一个数字为提问人ID，第二个数字为回答人数，后面则为所有回答人的ID。(ID均为0-1000000的整数)

输出描述:
第一行为作弊ID数量，第二行开始为从小到大的每行一个作弊ID。*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

struct data{
    set<int> view;
    set<int> cheat;
};

int main(){
    int N;
    while(cin>>N){
        vector<data > record;
        record.resize(105);
        int index, count, id;
        set<int> cheat;
        for(int i=0; i<N; i++){
            cin>>index>>count;
            while(index>record.size())
                record.resize(2*record.size());
            for(int j=0; j<count; j++){
                cin>>id;
                if(id == index)
                    continue;
                record[index].view.insert(id);
                if(record[id].view.find(index) != record[id].view.end()){
                    record[id].cheat.insert(index);
                    record[index].cheat.insert(id);
                    cheat.insert(id);
                    cheat.insert(index);
                }
            }
        }
        for(int i=0; i<record.size(); i++){
            bool ischeat = false;
            for(set<int>::iterator item = record[i].view.begin();
                    item != record[i].view.end(); item++){
                for(set<int>::iterator item2 = record[*item].cheat.begin();
                        item2 != record[*item].cheat.end(); item2++){
                    if(record[i].view.find(*item2) != record[i].view.end()){
                        cheat.insert(i);
                        ischeat = true;
                        break;
                    }
                }
                if(ischeat)
                    break;
            }
        }
        cout<<cheat.size()<<endl;
        for(set<int>::iterator item = cheat.begin();
                item != cheat.end(); item++){
            if(item == cheat.begin())
                cout<<*item;
            else
                cout<<" "<<*item;
        }
        if(cheat.size())
            cout<<endl;
    }
    return 0;
}
