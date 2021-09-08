//
// Created by dell on 2021/6/26.
//

#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 100000;

//定义结构体
struct Interval{
    int x;
    int y;
}interval[maxn];


int i_cmp(Interval a, Interval b){
    if (a.x !=  b.x){
        return a.x > b.x;
    } else{
        return a.y < b.y;
    }
}

int main(){

    //输入 n 个区间
    int n;
    while(cin >> n){
        for (int i =0 ; i < n ; i ++){
            cin >>interval[i].x >> interval[i].y;
        }
    }

    //排序
    std::sort(interval, &interval[maxn] , i_cmp);


    //看是否符合要求
    int lastX =  interval[0].x;
    int count = 0 ;
    for (int i = 1; i < n; i++) {
        if (lastX > interval[i].y){
            count++;
            lastX = interval[i].x;
        }
    }

    cout << count;



    return 0;
}

