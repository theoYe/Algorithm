//
// Created by dell on 2021/6/7.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace  std;
const int maxn = 11;
// P[maxn] 存放每个排列
// hashTable : 存放该排列中该数字是否已经出现过
int end_num, P[maxn], hashTable[maxn] = {false};
// a > b return true
// a < b return false
// 这里分数大到小，分数一样， 字典序小的排在前面，即从小到大
//bool cmp(int * a , int * b ){
//
//    for(int i= 0; i < 8 ;i ++){
//        if(a[i] > b[i]){
//            //首位大
//        }
//
//    }
//
//}
int count = 0;
int queen_table[92][8]={0};

void generateP(int index){
    if(index == end_num+1){
        bool  flag = true;
        for(int i = 1; i <= end_num; i ++){
            for(int j = i + 1; j <=end_num;j++){
                if(abs(i - j) == abs(P[i] - P[j])){
                    flag = false;  //不合法
                }
            }
//            printf("%d", P[i]);
        }

        //为八皇后正确解
        if(flag){
            for(int i=0 ;i < 8 ;i ++){
                queen_table[::count][i] = P[i+1];  //赋值
            }
            ::count++;
        }
//        printf("\n");
        return ;
    }

    for(int x = 1; x <= end_num; x++){
        if(hashTable[x] == false){
            P[index] = x;   //p[1] = 1 p[1] =2 , p[3] = 3
            hashTable[x] = true;
            generateP(index  + 1);  //generateP(2) generateP(2) generateP(2)
            hashTable[x] = false;
        }
    }
}


int main(){


    int m= 0;
    int in; //输入数据个数

    end_num = 8;
    generateP(1);

    cin >> in;
    for(int i= 0 ;i< in; i++){
        cin>>m;

        for(int j= 0 ; j < 8; j++){
            printf("%d", queen_table[m- 1][j]);
        }
        printf("\n");
        //无需排序，这里已经是默认序
//        sort(queen_table, queen_table + 92, cmp);

    }

    return 0;
}
