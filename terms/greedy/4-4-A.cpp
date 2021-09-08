//
// Created by dell on 2021/6/26.

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct tvShow{
    int si; //开始时间
    int ei; //结束时间
}tv[1001];

//左边从大到小排序
int cmp(tvShow t1, tvShow t2){
    if(t1.si != t2.si) return t1.si > t2.si;
    else return t1.si < t2.si;  //相同时按照右端点从小到大排序
}

int main(){

    int n, c;

    while(cin >> n , n){
        for(int i = 0;  i < n; i ++){
            cin >> tv[i].si >> tv[i].ei;
        }
        int arr[100];

        for(int i = 0;  i < 100; i ++){
            arr[i] = 0;
        }
    }

    return 0;
}

