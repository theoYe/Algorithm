//
// Created by dell on 2021/6/26.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct mooncake{
    double store; //库存
    double sell; //总售价
    double price; // 单价
}cake[1001];



bool cmp(mooncake  a, mooncake b){
    return a.price > b.price;
}


int main(){
    int n;
    double D;

    cin >> n >> D;

    for(int i= 0 ; i < n; i ++){
        cin >> cake[i].store;
    }

    for(int i = 0;  i < n; i ++){

        cin >> cake[i].sell;
        cake[i].price = cake[i].sell / cake[i].store;  //计算单价
    }


    sort(cake , cake + n, cmp);
    double ans = 0; //收益

    for(int i =0 ; i < n ; i ++){
        if(cake[i].store <= D){   // 如果需求量高于月饼需求量
            D-= cake[i].store;    //第 i 种月饼全部卖出
            ans += cake[i].sell;

        }else{   //如果月饼库存量高于需求量
            ans += cake[i].price * D;  //只卖出剩余需求量的月饼
            break;
        }
    }

    printf("%.2f\n", ans);
    return 0;
}


