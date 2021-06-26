//
// Created by dell on 2021/6/26.
//

//http://codeup.hustoj.com/problem.php?cid=100000583&pid=2


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 11;
// P[maxn] 存放每个排列
// hashTable : 存放该排列中该数字是否已经出现过
int P[maxn], hashTable[maxn] = {false};

//物品体积
int arr[50] = {0};
//个数计算
int ncount =0;

#define  VOLUME 40

//生成数字 start-end 的 长度为 l 的排列
//l 为当前长度(迭代使用的变量), n为数字长度
void genP(int index,int start, int end, int n, int l){
    //长度满足
    if(l==0){
        int sum = 0;
        for(int i=1 ;i <=n;i++){
            sum += arr[P[index-i]]; //添加物品体积
        }
        //刚好放下
        if(sum == VOLUME){
            ncount++;
        }
    }


    for(int i= start; i <= end ; i++){
        P[index] = i;
        genP(index+1,  i+1,end,n,l-1);
    }
}


int main(){

    int n;
    while(cin >> n){
        //物品容量
        for(int i = 0;  i < n; i ++){
            cin>>arr[i + 1];  //第 i 为 第i 个物体
        }

        //从 1到 n遍历
        for(int i= 1 ;i  <= n ; i++){
            // 产生全排列 1-n , 长度为i
            genP(1,1,n , i,i);
        }

        printf("%d\n", ncount);

        ncount = 0;
    }
    return 0;
}

