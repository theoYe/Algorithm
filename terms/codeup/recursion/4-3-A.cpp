//
// Created by dell on 2021/6/7.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//int get_plan(int total_choc, int day){
//    if(day<= 0){
//        if (total_choc==0) return 1;
//        else return 0;
//    }
//    else{
//        if (total_choc <=0) return 0;
//    }
//
//    return get_plan(total_choc -2, day -1) + get_plan(total_choc -1, day - 1);
//}

int get_plan(int total_choc, int day){
    if( (day<=0 && total_choc !=0 ) || (total_choc<0 && day != 0) ) return 0;
    if (total_choc==0) return 1;

    return get_plan(total_choc -2, day -1) + get_plan(total_choc -1, day - 1);
}


int main(){
    int n;
    while(cin >> n){
        printf("%d\n", get_plan(n , n));
    }
    return 0;
}
